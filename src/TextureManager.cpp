/*
 * TextureManager.cpp
 *
 *  Created on: Apr 2, 2018
 *      Author: dean
 */
#include <iostream>
#include <jsoncpp/json/json.h>
#include <fstream>
#include "TextureManager.h"
#include "AssetManager.h"
#include "log.hpp"


TextureManager::TextureManager(std::string index):_i(0) {
	LOG("TextureManager: Constructor");
	std::ifstream ifs(index);		// Load Index file
	Json::Reader reader;			// Create a reader
	Json::Value root;				// Create a JSON object named root
	reader.parse(ifs, root); 		// Read data into root
	Json::Value assets = root["assets"];
	for(std::string  asset:assets.getMemberNames()){
		std::string file_name = assets[asset]["file"].asString();
		LOG("TextureManager: Adding ",file_name);
		this->push_asset(file_name, asset);
	}

}

sf::Texture* TextureManager::_load_asset(std::string file_name) {
	return new ByteArray(file_name);
}

void TextureManager::_lock_up() {
	_lock.lock();
}

void TextureManager::_unlock() {
	_lock.unlock();
}

unsigned int TextureManager::push_asset(std::string file_name,
		std::string asset_name) {
	unsigned asset_id =_i;
	_i++;
	_ids_strings[asset_id] = asset_name;
	_strings_ids[asset_name] = asset_id;
	_ids_assets[asset_id] = _load_asset(file_name);
	return asset_id;
}

sf::Texture* TextureManager::get_asset(unsigned int asset_id) {
	return _ids_assets[asset_id];
}

sf::Texture* TextureManager::get_asset(std::string asset_name) {
	return get_asset(_strings_ids[asset_name]);
}

void TextureManager::free_asset(unsigned int asset_id) {
	std::string asset_name=_ids_strings[asset_id];
	_free_asset(asset_id, asset_name);
}

void TextureManager::free_asset(std::string asset_name) {
	int asset_id =_strings_ids[asset_name];
	_free_asset(asset_id, asset_name);
}

void TextureManager::_free_asset(unsigned int asset_id, std::string asset_name) {
	LOG("TextureManager: Freeing ", asset_name);
	_lock_up();
	sf::Texture *delete_me = _ids_assets[asset_id];
	_ids_strings.erase(asset_id);
	_strings_ids.erase(asset_name);
	_ids_assets.erase(asset_id);
	if(delete_me) {delete delete_me;}
	_unlock();
}

//Copy Constructor
TextureManager::TextureManager(const TextureManager& that):
			_i(that._i),
			_strings_ids(that._strings_ids),
			_ids_strings(that._ids_strings),
			_ids_assets(that._ids_assets)
			{LOG("TextureManager: Copy Constructor");}


//Copy Constructor
TextureManager::TextureManager(const TextureManager* that):
			_i(that->_i),
			_strings_ids(that->_strings_ids),
			_ids_strings(that->_ids_strings),
			_ids_assets(that->_ids_assets)
			{LOG("TextureManager: Copy Constructor");}


TextureManager::~TextureManager() {
	LOG("AssetManager: Destructor");
	for(auto id_string:_ids_strings){
		unsigned asset_id = id_string.first;
		free_asset(asset_id);
	}
}



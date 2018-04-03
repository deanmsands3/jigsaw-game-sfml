/*
 * AssetManager.cpp
 *
 *  Created on: Mar 10, 2018
 *      Author: deansands
 */

#include <iostream>
#include <jsoncpp/json/json.h>
#include <fstream>
#include "AssetManager.h"
#include "log.hpp"

AssetManager::AssetManager(std::string index):_i(0) {
	LOG("AssetManager: Constructor");
	std::ifstream ifs(index);		// Load Index file
	Json::Reader reader;			// Create a reader
	Json::Value root;				// Create a JSON object named root
	reader.parse(ifs, root); 		// Read data into root
	Json::Value assets = root["assets"];
	for(std::string  asset:assets.getMemberNames()){
		std::string file_name = assets[asset]["file"].asString();
		LOG("AssetManager: Adding ",file_name);
		this->push_asset(file_name, asset);
	}

}

unsigned int AssetManager::push_asset(std::string file_name,
		std::string asset_name) {
	unsigned asset_id =_i;
	_i++;
	_ids_strings[asset_id] = asset_name;
	_strings_ids[asset_name] = asset_id;
	_ids_assets[asset_id] = _load_asset(file_name);
	return asset_id;
}

ByteArray* AssetManager::get_asset(unsigned int asset_id) {
	return _ids_assets[asset_id];
}

ByteArray* AssetManager::get_asset(std::string asset_name) {
	return get_asset(_strings_ids[asset_name]);
}

void AssetManager::free_asset(unsigned int asset_id) {
	std::string asset_name=_ids_strings[asset_id];
	_free_asset(asset_id, asset_name);
}

void AssetManager::free_asset(std::string asset_name) {
	int asset_id =_strings_ids[asset_name];
	_free_asset(asset_id, asset_name);
}

void AssetManager::_free_asset(unsigned int asset_id, std::string asset_name) {
	LOG("AssetManager: Freeing ", asset_name);
	_lock_up();
	ByteArray *delete_me = _ids_assets[asset_id];
	_ids_strings.erase(asset_id);
	_strings_ids.erase(asset_name);
	_ids_assets.erase(asset_id);
	if(delete_me) {delete delete_me;}
	_unlock();
}

ByteArray* AssetManager::_load_asset(std::string file_name) {
//	// Open new file stream
//	std::fstream asset_file (file_name, std::ios::in | std::ios::binary);
//	// Find file size
//    asset_file.seekg (0, asset_file.end);
//    unsigned int length = asset_file.tellg();
//    asset_file.seekg (0, asset_file.beg);
//    // Allocate data
//    char *data=new char[length];
//    //Read in data
//    asset_file.read(data, length);
//    return (void*)data;
	return new ByteArray(file_name);
}

//Copy Constructor
AssetManager::AssetManager(const AssetManager& that):
	_i(that._i),
	_strings_ids(that._strings_ids),
	_ids_strings(that._ids_strings),
	_ids_assets(that._ids_assets)
	{LOG("AssetManager: Copy Constructor");}

//Copy Constructor
AssetManager::AssetManager(const AssetManager* that):
	_i(that->_i),
	_strings_ids(that->_strings_ids),
	_ids_strings(that->_ids_strings),
	_ids_assets(that->_ids_assets)
	{LOG("AssetManager: Copy Constructor");}

void AssetManager::_lock_up() {
	_lock.lock();
}

void AssetManager::_unlock() {
	_lock.unlock();
}

//Destructor
AssetManager::~AssetManager() {
	LOG("AssetManager: Destructor");
	for(auto id_string:_ids_strings){
		unsigned asset_id = id_string.first;
		free_asset(asset_id);
	}
}

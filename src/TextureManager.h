/*
 * TextureManager.h
 *
 *  Created on: Apr 2, 2018
 *      Author: dean
 */

#ifndef SRC_TEXTUREMANAGER_H_
#define SRC_TEXTUREMANAGER_H_
#include <SFML/Graphics.hpp>
#include "AssetManager.h"

class TextureManager {
	unsigned int _i;
	std::mutex _lock;
	std::unordered_map<std::string, unsigned int> _strings_ids;
	std::unordered_map<unsigned int, std::string> _ids_strings;
	std::unordered_map<unsigned int, sf::Texture*> _ids_assets;
	void _free_asset(unsigned int asset_id, std::string asset_name);
	static sf::Texture* _load_asset(std::string file_name);
	void _lock_up();
	void _unlock();
public:
	unsigned int push_asset(std::string file_name, std::string asset_name);
	sf::Texture* get_asset(unsigned int asset_id);
	sf::Texture* get_asset(std::string asset_name);
	void free_asset(unsigned int asset_id);
	void free_asset(std::string asset_name);
	TextureManager(std::string index);
	TextureManager(const TextureManager &that);
	TextureManager(const TextureManager *that);
	virtual ~TextureManager();
};

#endif /* SRC_TEXTUREMANAGER_H_ */

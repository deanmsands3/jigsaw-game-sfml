/*
 * AssetManager.h
 *
 *  Created on: Mar 10, 2018
 *      Author: deansands
 */

#ifndef ASSETMANAGER_H_
#define ASSETMANAGER_H_
#include <unordered_map>
#include <string>
#include <cstdint>

class ByteArray{
	unsigned long _length;
	char* _data;
public:
	char* data() const;
	ByteArray();
	ByteArray(unsigned long length);
	ByteArray(std::string file_name);
	~ByteArray();
};

class AssetManager {
	unsigned int _i;
	std::unordered_map<std::string, unsigned int> _strings_ids;
	std::unordered_map<unsigned int, std::string> _ids_strings;
	std::unordered_map<unsigned int, void*> _ids_assets;
	void _free_asset(unsigned int asset_id, std::string asset_name);
	static void *_load_asset(std::string file_name);
public:
	unsigned int push_asset(std::string file_name, std::string asset_name);
	void* get_asset(unsigned int asset_id);
	void* get_asset(std::string asset_name);
	void free_asset(unsigned int asset_id);
	void free_asset(std::string asset_name);
	AssetManager(std::string index);
	virtual ~AssetManager();
};

#endif /* ASSETMANAGER_H_ */

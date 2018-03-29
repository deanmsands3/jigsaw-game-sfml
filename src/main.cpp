#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "PuzzlePiece.h"
#include "AssetManager.h"
#include "GameWindow.h"
#include "GameMenu.h"

int main()
{
	std::string index("index.json");

	std::shared_ptr<AssetManager> assets=std::make_shared<AssetManager>(new AssetManager(index));
	GameWindowManager gwm(assets);
	std::shared_ptr<GameWindow> gw=gwm.newWindow<GameMenu>();
	gwm.open_window(gw);
    //std::cout << "Hello world! Desktop test 1";
    
    return 0;
}


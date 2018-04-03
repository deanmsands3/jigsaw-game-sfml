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
#include "log.hpp"
int main()
{
	LOG("main: Game start!");
	std::shared_ptr<AssetManager> assets=std::make_shared<AssetManager>(new AssetManager("index.json"));
	LOG("main: Asset manager created");
	GameWindowManager gwm(assets);
	LOG("main: GameWindowManager created");
	std::shared_ptr<GameWindow> gw=gwm.newWindow<GameMenu>();
	LOG("main: GameMenu created");
	gwm.open_window(gw);
	LOG("main: GameMenu opened");
    
	LOG("main: Game Over, man!");
    return 0;
}


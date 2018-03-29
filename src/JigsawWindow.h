/*
 * JigsawMenu.h
 *
 *  Created on: Mar 10, 2018
 *      Author: deansands
 */

#ifndef SRC_JIGSAWWINDOW_H_
#define SRC_JIGSAWWINDOW_H_

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <memory>
#include "GameMenu.h"

class JigsawWindow:public GameMenu {
    sf::RenderWindow jigsawWindow;
    std::vector <std::vector <std::string> > gameSet;
    std::vector <std::vector <std::string> > gamePieces;
    std::vector <std::vector <std::string> > temp;
    std::vector<sf::Sprite> gamePiece;
public:
	JigsawWindow(std::shared_ptr<GameWindowManager> game_window_manager);
	virtual ~JigsawWindow();
	void jigsawToVector();
};





#endif /* SRC_JIGSAWWINDOW_H_ */

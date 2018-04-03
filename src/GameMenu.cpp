/*
 * GameMenu.cpp
 *
 *  Created on: Mar 10, 2018
 *      Author: deansands
 */

#include <iostream>
#include "GameMenu.h"
GameMenu::GameMenu(std::shared_ptr<GameWindowManager> game_window_manager):GameWindow(game_window_manager) {

}

void GameMenu::_setup() {
//	if(! (mainFont.loadFromMemory()))
//		std::cerr << std::endl << "Error loading font 'Georgia.ttf'" << std::endl;
//
//	menuTitleText = "Jigsaw Time!";
//
//	menuHintText = "Hi! Welcome to Jigsaw Time! There is lots of awesome landscape jigsaw puzzle fun to be had!";
//	menuExitButtonWordText = "Quit";
//
//	textColor = sf::Color::Black;
//	backgroundColor = sf::Color::White;
//
//	buttonColor1.r = 200;
//	buttonColor1.g = 202;
//	buttonColor1.b = 206;
//
//	buttonColor2.r = 227;
//	buttonColor2.g = 228;
//	buttonColor2.b = 232;
//
//	menuTitle.setCharacterSize(titleTextSize);
//	menuHint.setCharacterSize(textSize);
//	menuExitButtonWord.setCharacterSize(textSize);
//
//	menuTitle.setFillColor(textColor);
//	menuHint.setFillColor(textColor);
//	menuExitButtonWord.setFillColor(textColor);
//
//	menuTitle.setString(menuTitleText);
//	menuHint.setString(menuHintText);
//	menuExitButtonWord.setString(menuExitButtonWordText);
//
//	image1.loadFromMemory();
//	image2.loadFromFile("../img/landscape2.jpg");
//	image3.loadFromFile("../img/landscape3.jpg");
//	image4.loadFromFile("../img/landscape4.jpg");
//	image5.loadFromFile("../img/landscape5.jpg");
//
//	choiceImage1.setTexture(image1);
//	choiceImage2.setTexture(image2);
//	choiceImage3.setTexture(image3);
//	choiceImage4.setTexture(image4);
//	choiceImage5.setTexture(image5);
//
//	titleRect.setFillColor(buttonColor1);
//	buttonRect.setFillColor(buttonColor2);
//
//	choiceImage1Pos = (sf::Vector2f(0, 0));
//	choiceImage2Pos = (sf::Vector2f(0, 0));
//	choiceImage3Pos = (sf::Vector2f(0, 0));
//	choiceImage4Pos = (sf::Vector2f(0, 0));
//	choiceImage5Pos = (sf::Vector2f(0, 0));
//	menuTitlePos = (sf::Vector2f(0, 0));
//	menuHintPos = (sf::Vector2f(0, 0));
//	menuExitButtonWord1Pos = (sf::Vector2f(0, 0));
//	titleRectPos = (sf::Vector2f(0, 0));
//	buttonRectPos = (sf::Vector2f(0, 0));
//	menuWindowLocation = (sf::Vector2f(0, 0));
//
//	menuWindowSize = (sf::Vector2f(0, 0));

}

GameMenu::~GameMenu() {

}


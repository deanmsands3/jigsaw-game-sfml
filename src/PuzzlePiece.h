/******************************************************************************\
* File:    PuzzlePiece.h                                                       *
* Author:  Dean M. Sands, III                                                  *
* Purpose: Class and Manager for JigSaw Game Pieces                            *
* License: I will come to your house and set fire to your lawn flamingos.      *
\******************************************************************************/

#ifndef __PUZZLEPIECE_H__
#define __PUZZLEPIECE_H__
#include <SFML/Graphics.hpp>
#include <vector>
#include <unordered_map>
#include <string>

#include "Entity.h"

class PuzzlePiece: public Entity{
public:
  PuzzlePiece(unsigned int id, sf::Sprite sprite);
  virtual ~PuzzlePiece();

  friend class PuzzlePieceManager;

};

class PuzzlePieceManager{
  std::vector<std::string> _files;
  std::unordered_map<unsigned int, PuzzlePiece> _game_pieces;
public:
  PuzzlePieceManager();
  virtual ~PuzzlePieceManager();
};



#endif

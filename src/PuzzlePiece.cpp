#include "PuzzlePiece.h"

PuzzlePieceManager::PuzzlePieceManager() {
}

PuzzlePieceManager::~PuzzlePieceManager() {
}

PuzzlePiece::PuzzlePiece(unsigned int id, sf::Sprite sprite):Entity(id, sprite){
}

PuzzlePiece::~PuzzlePiece() {
}

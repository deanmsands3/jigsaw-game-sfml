/*
 * Entities.cpp
 *
 *  Created on: Mar 10, 2018
 *      Author: deansands
 */

#include "Entity.h"


Entity::Entity(unsigned int id, sf::Sprite sprite):_id(id),_sprite(sprite) {
}

Entity::~Entity() {
}

unsigned int Entity::getId() const {
	return _id;
}

sf::Vector2f Entity::getPosition() const {
	return _position;
}

void Entity::setPosition(sf::Vector2f position) {
	_position = position;
}

const sf::Sprite& Entity::getSprite() const {
	return _sprite;
}

void Entity::setSprite(const sf::Sprite& sprite) {
	_sprite = sprite;
}

void Entity::update(float t) {
}

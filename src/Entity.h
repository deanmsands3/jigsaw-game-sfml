/*
 * Entities.h
 *
 *  Created on: Mar 10, 2018
 *      Author: deansands
 */

#ifndef SRC_ENTITY_H_
#define SRC_ENTITY_H_
#include <SFML/Graphics.hpp>
#include <memory>
#include "AssetManager.h"


class Entity {
  unsigned int _id;
  sf::Vector2f _position;
  sf::Sprite _sprite;
public:
	Entity(unsigned int id, sf::Sprite sprite);
	virtual ~Entity();
	unsigned int getId() const;
	sf::Vector2f getPosition() const;
	void setPosition(sf::Vector2f position);
	const sf::Sprite& getSprite() const;
	void setSprite(const sf::Sprite& sprite);
	virtual void update(float t);
	virtual void draw();

};


#endif /* SRC_ENTITY_H_ */

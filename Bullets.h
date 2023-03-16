#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
#include "Player.h"

class Bullets {
private:sf::Texture texture;
	   sf::Sprite sprite;
	   float speed = Bullet_speed, speedx, speedy;
public:
	Bullets(sf::Vector2f playerPos, int playerAngle) {
		texture.loadFromFile(Bullets_File_Name);
		sprite.setTexture(texture);
		sprite.setRotation(playerAngle);
		sf::FloatRect bounds = sprite.getLocalBounds();
		sprite.setOrigin(bounds.width / 2, bounds.height / 2);
		sprite.setPosition(playerPos);
		speedx = speed * cos(playerAngle * PI / 180);
		speedy = -speed * sin(playerAngle * PI / 180);
	}
	void update() {
			sprite.move(speedx, speedy);
	}

	sf::Sprite& getSprite() { return sprite; }
};

#pragma once
#include "settings.h"
#include <list>

class Player {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	int angle;
	float speed, speedx, speedy;
	std::list<Bullets*>bullets;
public:
	Player() {
		texture.loadFromFile(Player_File_Name);
		sprite.setTexture(texture);
		sf::FloatRect bounds = sprite.getLocalBounds();
		sprite.setOrigin(bounds.width / 2, bounds.height / 2);
		sprite.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		angle = 0;
		speed = 0.f;
	}
	void update() {
		speed = 1.f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			speed = 5;
		}
		if (sprite.getPosition().x <= 0 + Fon_offset) {
			sprite.setPosition(0 + Fon_offset, sprite.getPosition().y);
		}
		if (sprite.getPosition().x >= WINDOW_WIDTH - Fon_offset) {
			sprite.setPosition(WINDOW_WIDTH - Fon_offset, sprite.getPosition().y);
		}
		if (sprite.getPosition().y <= 0 + Fon_offset) {
			sprite.setPosition(sprite.getPosition().x, 0 + Fon_offset);
		}
		if (sprite.getPosition().y >= WINDOW_HEIGHT - Fon_offset) {
			sprite.setPosition(sprite.getPosition().x, WINDOW_HEIGHT - Fon_offset);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			angle -= 3;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			angle += 3;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { speed = 0.f; }
		sprite.setRotation(angle);
		speedx = speed * cos(angle * PI / 180);
		speedy = -speed * sin(angle * PI / 180);
		sprite.move(speedx, speedy);
		fire();
		for (auto bullet::bullets) {
			bullet->update();
		}
	}
	void fire() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

		}
	}
	sf::Sprite& getSprite() { return sprite; }
	void draw(sf::RenderWindow& window) {
		sprite.draw();
	}
};



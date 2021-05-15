#pragma  once

#include "SFML/Graphics.hpp"
#include <experimental/random>
#include <iostream>
#define REPRODUCTION_THRESHOLD 100

class Person {
public:
	Person(sf::Vector2f position, int maxAge, int strength, int reproductionBonus);
	Person(sf::Vector2f position, int maxAge, int strength, int reproductionBonus, bool mutation);
	~Person();
	static int createdPersons;
	void update();
	sf::Vector3i getColor();
	int getAge() { return age; };
	void reproduce();
	int getStrength() const { return strength; };
	bool isAlive() { return alive; };
	void kill();
	int getReproductionValue() { return reproductionValue; };
	bool checkReproduction();
	int getreproductionBonus() { return reproductionBonus; };
	sf::Vector2f getPosition() const { return position; };
	void setPosition(sf::Vector2f new_position);
private:
	void mutate();
	void scan();
	void reproduction();
	int reproductionValue;
	sf::Vector2f position;
	bool alive;
	int age;
	int reproductionBonus;
	int maxAge;
	int strength;
	sf::Vector3i color;
};

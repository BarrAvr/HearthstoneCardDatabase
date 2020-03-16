#include "Weapon.h"
#include <iostream>
#include <string>

//Constructors
Weapon::Weapon() {
	name = "";
	manaCost = 0;
	cardClass = Spell::NEUTRAL;
	rarity = Spell::COMMON;
	description = "";
	sortKey = Spell::NAME;
	attackValue = 0;
	durability = 0;
}
Weapon::Weapon(std::string newName, int cost, ClassType newClass, Rarity newRarity, std::string newDescription, int attack, int newDurability, key sortKey) {
	name = newName;
	manaCost = cost;
	cardClass = newClass;
	rarity = newRarity;
	description = newDescription;
	sortKey = sortKey;
	attackValue = attack;
	durability = newDurability;
}
//Destructor
Weapon::~Weapon() {

}
//getters
int Weapon::getAttackValue() const {
	return attackValue;
}
int Weapon::getDurability() const {
	return durability;
}
//std::string getCardType() { return "Weapon"; };
//setters
void Weapon::setAttackValue(int newAttack) {
	attackValue = newAttack;
}
void Weapon::setDurability(int newDurability) {
	durability = newDurability;
}

std::istream& operator>>(std::istream& in, Weapon& toRead) {

}

std::ostream& operator<<(std::ostream& out, const Weapon& toPrint) {

}
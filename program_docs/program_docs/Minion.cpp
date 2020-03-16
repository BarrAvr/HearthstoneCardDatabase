#include "Minion.h"
#include <iostream>
#include <string>

//Constructors
Minion::Minion()
{
	name = "";
	manaCost = 0;
	cardClass = Spell::NEUTRAL;
	rarity = Spell::COMMON;
	description = "";
	sortKey = Spell::NAME;
	attackValue = 0;
	healthValue = 0;
}
Minion::Minion(std::string newName, int cost, ClassType newClass, Rarity newRarity, std::string newDescription, int attack, int newHealth, key newSortKey) {
	name = newName;
	manaCost = cost;
	cardClass = newClass;
	rarity = newRarity;
	description = newDescription;
	sortKey = newSortKey;
	attackValue = attack;
	healthValue = newHealth;
}
//Destructor
Minion::~Minion() {

}
//getters
int Minion::getAttackValue() const {
	return attackValue;
}
int Minion::getHealthValue() const {
	return durability;
}
//std::string getCardType() { return "Weapon"; };
//setters
void Minion::setAttackValue(int newAttack) {
	attackValue = newAttack;
}
void Minion::setHealthValue(int newDurability) {
	durability = newDurability;
}

std::istream& operator>>(std::istream& in, Minion& toRead) {

}

std::ostream& operator<<(std::ostream& out, const Minion& toPrint) {

}
#include "Minion.h"
#include <iostream>
#include <string>

//Constructors
Minion::Minion()
	: name(""), manaCost(0), cardClass(0), rarity(0), description(""), flavorText(""), sortKey(0), attackValue(0), healthValue(0)
{

}
Minion::Minion(std::string name, int cost, ClassType cardClass, Rarity rarity, std::string description, std::string flavor, int attack, int health, key sortKey)
	: name(name), manaCost(cost), cardClass(cardClass), rarity(rarity), description(description), flavorText(flavor), attackValue(attack), healthValue(health), sortKey(sortKey)
{

}
//Destructor
Minion::~Minion() {

}
//getters
int Minion::getAttackValue() {
	return attackValue;
}
int Minion::getHealthValue() {
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
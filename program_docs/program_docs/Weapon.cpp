#include "Weapon.h"
#include <iostream>
#include <string>

//Constructors
Weapon::Weapon() 
	: name(""), manaCost(0), cardClass(0), rarity(0), description(""), flavorText(""), sortKey(0), attackValue(0), durability(0)
{

}
Weapon::Weapon(std::string name, int cost, ClassType cardClass, Rarity rarity, std::string description, std::string flavor, int attack, int durability, key sortKey)
	: name(name), manaCost(cost), cardClass(cardClass), rarity(rarity), description(description), flavorText(flavor), attackValue(attack), durability(durability), sortKey(sortKey)
{

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
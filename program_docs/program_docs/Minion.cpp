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
	return healthValue;
}
//std::string getCardType() { return "Weapon"; };
//setters
void Minion::setAttackValue(int newAttack) {
	attackValue = newAttack;
}
void Minion::setHealthValue(int newHealthValue) {
	healthValue = newHealthValue;
}

void Minion::print(std::ostream& out) const {
	out << "CardType: Minion\n" <<
		"Mana Cost: " << this->getManaCost() << std::endl
		<< "Name: " << this->getName() << std::endl
		<< "ClassType: " << classEnumToString(this->getClass()) << std::endl
		<< "Description: " << this->getDescription() << std::endl
		<< "Rarity: " << rarityEnumToString(this->getRarity()) << std::endl
		<< "Attack/Health: " << this->getAttackValue() << "/" << this->getHealthValue() << std::endl << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Minion& toPrint) {
	toPrint.print(out);
	return out;
}
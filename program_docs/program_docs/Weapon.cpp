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
Weapon::Weapon(std::string newName, int cost, ClassType newClass, Rarity newRarity, std::string newDescription, int attack, int newDurability, key newSortKey) {
	name = newName;
	manaCost = cost;
	cardClass = newClass;
	rarity = newRarity;
	description = newDescription;
	sortKey = newSortKey;
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

//setters
void Weapon::setAttackValue(int newAttack) {
	attackValue = newAttack;
}
void Weapon::setDurability(int newDurability) {
	durability = newDurability;
}

//misc
void Weapon::print(std::ostream& out) const {
	out << "CardType: Weapon\n" <<
		"Mana Cost: " << this->getManaCost() << std::endl
		<< "Name: " << this->getName() << std::endl
		<< "ClassType: " << this->getClass() << std::endl 
		<< "Description: " << this->getDescription() << std::endl
		<< "Attack/Health: " << this->getAttackValue() << "/" << this->getDurability() << std::endl << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Weapon& toPrint) {
	toPrint.print(out);
	return out;
}
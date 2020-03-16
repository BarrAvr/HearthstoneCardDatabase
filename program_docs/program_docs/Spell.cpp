#include "Spell.h"
#include "Minion.h"
#include "Weapon.h"

/*
	std::string name;
	int manaCost;
	int key;
	ClassType cardClass;
	Rarity rarity;
	std::string description;
	std::string flavorText;
*/

//Constructors
Spell::Spell() {
	name = "";
	manaCost = 0;
	cardClass = Spell::NEUTRAL;
	rarity = Spell::COMMON;
	description = "";
	sortKey = Spell::NAME;
}
Spell::Spell(std::string newName, int cost, ClassType newClass, Rarity newRarity, std::string newDescription, key newSortKey) {
	name = newName;
	manaCost = cost;
	cardClass = newClass;
	rarity = newRarity;
	description = newDescription;
	sortKey = newSortKey;
}
//Destructor
Spell::~Spell() {

}
//getters
std::string Spell::getName() const {
	return name;
}
int Spell::getManaCost() const {
	return manaCost;
}
Spell::ClassType Spell::getClass() const {
	return cardClass;
}
Spell::Rarity Spell::getRarity() const {
	return rarity;
}
Spell::key Spell::getKey() const {
	return sortKey;
}
std::string Spell::getDescription() const {
	return description;
}
//virtual std::string getCardType() { return "Spell"; };
//setters
void Spell::setName(std::string newName) {
	name = newName;
}
void Spell::setManaCost(int newCost) {
	manaCost = newCost;
}
void Spell::setClass(ClassType newClass) {
	cardClass = newClass;
}
void Spell::setRarity(Rarity newRarity) {
	rarity = newRarity;
}
void Spell::setDescription(std::string newDescription) {
	description = newDescription;
}
//overloads
bool Spell::operator>(Spell& card) const {
	bool isGreater;
	if (this->sortKey != card.getKey()) {
		//throw error
		return false;
	}
	if (this->sortKey == NAME) {
		isGreater = this->name > card.getName();
	}
	else if (this->sortKey == MANA) {
		isGreater = this->manaCost > card.getManaCost();
	}
	else if (this->sortKey == CLASS) {
		isGreater = this->cardClass > card.getClass();
	}
	else if (this->sortKey == RARITY) {
		isGreater = this->rarity > card.getRarity();
	}
	else {
		isGreater = this->description > card.getDescription();
	}
	return isGreater;
}

bool Spell::operator<(Spell& card) const {
	bool isLessThan;
	if (this->sortKey != card.getKey()) {
		//throw error
		return false;
	}
	if (this->sortKey == NAME) {
		isLessThan = this->name < card.getName();
	}
	else if (this->sortKey == MANA) {
		isLessThan = this->manaCost < card.getManaCost();
	}
	else if (this->sortKey == CLASS) {
		isLessThan = this->cardClass < card.getClass();
	}
	else if (this->sortKey == RARITY) {
		isLessThan = this->rarity < card.getRarity();
	}
	else {
		isLessThan = this->description > card.getDescription();
	}
	return isLessThan;
}

bool Spell::operator==(Spell& card) const {
	return this->name == card.getName() && this->manaCost == card.getManaCost() && this->cardClass == card.getClass() && this->rarity == card.getRarity() && this->description == card.getDescription();
}

void Spell::print(std::ostream& out) {
	out << "CardType: Spell\n" <<
		"Mana Cost: " << this->getManaCost() << std::endl
		<< "Name: " << this->getName() << std::endl
		<< "ClassType: " << this->getClass() << std::endl << std::endl
		<< "Description: " << this->getDescription() << std::endl << std::endl;
}

std::ostream& operator<<(std::ostream& out, Spell*& toPrint) {
	if (toPrint->getCardType() == "Spell") {
		toPrint->print(out);
	}
	else if (toPrint->getCardType() == "Minion") {
		dynamic_cast<Minion&>(*toPrint).print(out);
	}
	else {
		dynamic_cast<Weapon&>(*toPrint).print(out);
	}
	//if (toPrint->getCardType() == "Spell") {
	//	out << "CardType: Spell\n" <<
	//		"Mana Cost: " << toPrint->getManaCost() << std::endl
	//		<< "Name: " << toPrint->getName() << std::endl
	//		<< "ClassType: " << toPrint->getClass() << std::endl << std::endl
	//		<< "Description: " << toPrint->getDescription() << std::endl << std::endl;
	//}
	//else if (toPrint->getCardType() == "Minion") {
	//	out << "CardType: Minion\n" <<
	//		"Mana Cost: " << toPrint->getManaCost() << std::endl
	//		<< "Name: " << toPrint->getName() << std::endl
	//		<< "ClassType: " << toPrint->getClass() << std::endl << std::endl
	//		<< "Description: " << toPrint->getDescription() << std::endl << std::endl
	//		<< "Attack/Health: " << toPrint->getAttackValue() << "/" << toPrint->getDurability() << std::endl;
	//}

	////incomplete code
	//if (toRead->getCardType() == "Spell") {

	//}
	//else if (toRead->getCardType() == "Minion") {

	//}
	//else { 

	//}
	/*
	CardType: Spell
	Mana Cost: X
	Name: Joe Moose
	ClassType: Hunter

	Description:
	Random words.

	Flavor Text:
	Random words.

	Attack/Health: X/X
	Attack/Durability: X/X
	*/
}

#include "Spell.h"
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
Spell::Spell() 
	: name(""), manaCost(0), cardClass(0), rarity(0), description(""), flavorText(""), sortKey(0)
{

}
Spell::Spell(std::string name, int cost, ClassType cardClass, Rarity rarity, std::string description, std::string flavor, key sortKey) 
	: name(name), manaCost(cost), cardClass(cardClass), rarity(rarity), description(description), flavorText(flavor), sortKey(sortKey)
{

}
//Destructor
Spell::~Spell() {

}
//getters
std::string Spell::getName() {
	return name;
}
int Spell::getManaCost() {
	return manaCost;
}
ClassType Spell::getClass() {
	return cardClass;
}
Rarity Spell::getRarity() {
	return rarity;
}
key Spell::getKey() {
	return sortKey;
}
std::string Spell::getDescription() {
	return description;
}
std::string Spell::getFlavorText() {
	return flavorText;
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
void Spell::setFlavorText(std::string newText) {
	flavorText = newText;
}
//overloads
bool Spell::operator>(const Spell& card) const {
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

bool Spell::operator<(const Spell& card) const {
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

bool Spell::operator==(const Spell& card) const {
	return this->name == card.getName() && this->manaCost == card.getManaCost() && this->cardClass == card.getClass() && this->rarity == card.getRarity() && this->description == card.getDescription();
}

std::istream& operator>>(std::istream& in, Spell& toRead) {

}

std::istream& operator>>(std::istream& in, Spell&* toRead) {

}

std::ostream& operator<<(std::ostream& out, const Spell&* toPrint) {

	if (toPrint->getCardType() == "Spell") {
		out << "CardType: Spell\n" <<
			"Mana Cost: " << toPrint->getManaCost() << endl
			<< "Name: " << toPrint->getName() << endl
			<< "ClassType: " << toPrint->getClass() << endl << endl
			<< "Description: " << toPrint->getDescription() << endl << endl
			<< "Flavor Text: " << toPrint->getFlavorText() << endl;
	}
	else if (toPrint->getCardType() == "Minion") {
		out << "CardType: Minion\n" <<
			"Mana Cost: " << toPrint->getManaCost() << endl
			<< "Name: " << toPrint->getName() << endl
			<< "ClassType: " << toPrint->getClass() << endl << endl
			<< "Description: " << toPrint->getDescription() << endl << endl
			<< "Flavor Text: " << toPrint->getFlavorText() << endl << endl
			<< "Attack/Health: " << toPrint->getAttackValue() << "/" << toPrint->getDurability() << endl;
	}




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

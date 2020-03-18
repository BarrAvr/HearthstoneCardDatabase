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

void Spell::print(std::ostream& out) const {
	out << "CardType: Spell\n" <<
		"Mana Cost: " << this->getManaCost() << std::endl
		<< "Name: " << this->getName() << std::endl
		<< "ClassType: " << classEnumToString(this->getClass()) << std::endl
		<< "Description: " << this->getDescription() << std::endl
		<< "Rarity: " << rarityEnumToString(this->getRarity()) << std::endl << std::endl;
}
std::string Spell::rarityEnumToString(Spell::Rarity r) const {
	if (r == Spell::COMMON) return "Common";
	if (r == Spell::RARE) return "Rare";
	if (r == Spell::EPIC) return "Epic";
	if (r == Spell::LEGENDARY) return "Legendary";

}
std::string Spell::classEnumToString(Spell::ClassType ct) const{
	if (ct == Spell::DRUID) return "Druid";
	else if (ct == Spell::HUNTER) return "Hunter";
	else if (ct == Spell::MAGE) return "Mage";
	else if (ct == Spell::PALADIN) return "Paladin";
	else if (ct == Spell::PRIEST) return "Priest";
	else if (ct == Spell::ROGUE) return "Rogue";
	else if (ct == Spell::SHAMAN) return "Shaman";
	else if (ct == Spell::WARLOCK) return "Warlock";
	else if (ct == Spell::WARRIOR) return "Warrior";
	else if (ct == Spell::NEUTRAL) return "Neutral";
}
void Spell::printToTSVFile(std::ostream& out) {
	out  << this->getName() << "\t"
		<< this->getManaCost() << "\t"
		<< classEnumToString(this->getClass()) << "\t"
		<< this->getCardType() << "\t"
		<< rarityEnumToString(this->getRarity()) << "\t"
		<< this->getDescription();
	if (this->getCardType() == "Spell") {
		out << "\n";
	}
	else if (this->getCardType() == "Minion") {
		out << "\t"
			<< dynamic_cast<Minion&>(*this).getAttackValue() << "\t"
			<< dynamic_cast<Minion&>(*this).getHealthValue() << "\t"
			<< "\n";
	}
	else if (this->getCardType() == "Weapon") {
		out << "\t"
			<< dynamic_cast<Weapon&>(*this).getAttackValue() << "\t"
			<< dynamic_cast<Weapon&>(*this).getDurability() << "\t"
			<< "\n";
	}
}

std::ostream& operator<<(std::ostream& out, Spell*& toPrint) {
	if (toPrint->getCardType() == "Spell") {
		out << toPrint->getName() << "," << toPrint->getManaCost()
			<< "," << toPrint->getClass() << ","
			<< toPrint->getCardType() << ","
			<< toPrint->getRarity() << ","
			<< toPrint->getDescription() << std::endl;
	}
	else if (toPrint->getCardType() == "Minion") {
		out << toPrint->getName() << "," << toPrint->getManaCost()
			<< "," << toPrint->getClass() << ","
			<< toPrint->getCardType() << ","
			<< toPrint->getRarity() << ","
			<< toPrint->getDescription() << ","
			<< dynamic_cast<Minion&>(*toPrint).getAttackValue() << ","
			<< dynamic_cast<Minion&>(*toPrint).getHealthValue() << std::endl;
		
	}
	else {
		out << toPrint->getName() << "," << toPrint->getManaCost()
			<< "," << toPrint->getClass() << ","
			<< toPrint->getCardType() << ","
			<< toPrint->getRarity() << ","
			<< toPrint->getDescription() << ","
			<< dynamic_cast<Weapon&>(*toPrint).getAttackValue() << ","
			<< dynamic_cast<Weapon&>(*toPrint).getAttackValue() << std::endl;

	}
	return out;
}

std::ostream& operator<<(std::ostream& out, const Spell& toPrint) {
	toPrint.print(out);
	return out;
}

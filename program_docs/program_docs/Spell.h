#pragma once
#include <iostream>
#include <string>

class Spell {
public:
	static enum ClassType { NEUTRAL, DRUID, HUNTER, MAGE, PALADIN, PRIEST, ROGUE, SHAMAN, WARLOCK, WARRIOR };
	static enum Rarity { COMMON, RARE, EPIC, LEGENDARY };
	static enum key { NAME, MANA, CLASS, RARITY, DESCRIPTION };
protected:
	std::string name;
	int manaCost;
	key sortKey;
	ClassType cardClass;
	Rarity rarity;
	std::string description;
	std::string flavorText;
public:
	//Constructors
	Spell();
	Spell(std::string, int, ClassType, Rarity, std::string, std::string, key);
	//Destructor
	~Spell();
	//getters
	std::string getName() const;
	int getManaCost() const;
	ClassType getClass() const;
	Rarity getRarity() const;
	key getKey() const;
	std::string getDescription() const;
	std::string getFlavorText() const;
	virtual std::string getCardType() const { return "Spell"; };
	//setters
	void setName(std::string);
	void setManaCost(int);
	void setClass(ClassType);
	void setRarity(Rarity);
	void setDescription(std::string);
	void setFlavorText(std::string);
	//overloads
	bool operator>(Spell&) const;

	bool operator<(Spell&) const;

	bool operator==(Spell&) const;
	
	friend std::istream& operator>>(std::istream& in, Spell& toRead);

	friend std::istream& operator>>(std::istream& in, Spell& toRead);
	
	friend std::ostream& operator<<(std::ostream& out, Spell*& toPrint);
};
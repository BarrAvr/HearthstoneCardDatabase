//Spell by Barr
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
public:
	//Constructors
	Spell();
	Spell(std::string, int, ClassType, Rarity, std::string, key);
	//Destructor
	~Spell();
	//getters
	std::string getName() const;
	int getManaCost() const;
	ClassType getClass() const;
	Rarity getRarity() const;
	key getKey() const;
	std::string getDescription() const;
	virtual std::string getCardType() const { return "Spell"; };
	//setters
	void setName(std::string);
	void setManaCost(int);
	void setClass(ClassType);
	void setRarity(Rarity);
	void setDescription(std::string);
	std::string rarityEnumToString(Spell::Rarity) const;
	std::string classEnumToString(Spell::ClassType) const;
	void printToTSVFile(std::ostream& out);
	//misc
	virtual void print(std::ostream& out) const;
	//overloads
	/* for bool operator>(const Spell&) const

	Pre: name - name of card
	manaCost - mana cost of card
	sortKey - key to decide what to compare
	cardClass - class type of card
	rarity - rarity of card
	description - description of card

	Post: This program checks to see what the sorting
	key decides what variable to compare by, and
	then compares those variables. If the variable
	in this spell is greater than the variable in
	the other spell it returns true, otherwise it 
	returns false.

	Return: returns true if this spell is greater
	than the other one, false otherwise
	*/
	bool operator>(const Spell&) const;
	/* for bool operator>(const Spell&) const

	Pre: name - name of card
	manaCost - mana cost of card
	sortKey - key to decide what to compare
	cardClass - class type of card
	rarity - rarity of card
	description - description of card

	Post: This program checks to see what the sorting
	key decides what variable to compare by, and
	then compares those variables. If the variable
	in this spell is less than the variable in
	the other spell it returns true, otherwise it
	returns false.

	Return: returns true if this spell is less
	than the other one, false otherwise
	*/
	bool operator<(const Spell&) const;
	/* for bool operator>(const Spell&) const

	Pre: name - name of card
	manaCost - mana cost of card
	sortKey - key to decide what to compare
	cardClass - class type of card
	rarity - rarity of card
	description - description of card

	Post: This program compares every
	variable in the spell, and if they are
	equal returns true.

	Return: true if the spells are equal,
	false otherwise
	*/
	bool operator==(const Spell&) const;
	/* for bool operator>(const Spell&) const

	Pre: out - stream to print to
	toPrint - card to print

	Post: This program prints all of the
	information from toPrint to out

	Return: out
	*/
	friend std::ostream& operator<<(std::ostream& out, Spell*& toPrint);
	/* for bool operator>(const Spell&) const

	Pre: out - stream to print to
	toPrint - card to print

	Post: This program prints all of the
	information from toPrint to out

	Return: out
	*/
	friend std::ostream& operator<<(std::ostream& out, const Spell& toPrint);
};
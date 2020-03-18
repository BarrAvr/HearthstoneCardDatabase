#pragma once
#include <iostream>
#include "Spell.h"

class Weapon : public Spell {
private:
	int attackValue;
	int durability;
public:
	//Constructors
	Weapon();
	Weapon(std::string, int, ClassType, Rarity, std::string, int, int, key);
	//Destructor
	~Weapon();
	//getters
	int getAttackValue()const;
	int getDurability()const;
	std::string getCardType() const { return "Weapon"; };
	//setters
	void setAttackValue(int);
	void setDurability(int);
	//misc
	/* for bool operator>(const Spell&) const

	Pre: out - stream to print to
	toPrint - card to print

	Post: This program prints all of the
	information from toPrint to out

	Return: nothing
	*/
	void print(std::ostream& out) const;
	/* for bool operator>(const Spell&) const

	Pre: out - stream to print to
	toPrint - card to print

	Post: This program prints all of the
	information from toPrint to out

	Return: out
	*/
	friend std::ostream& operator<<(std::ostream& out, const Weapon& toPrint);
};

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

	friend std::istream& operator>>(std::istream& in, Weapon& toRead);

	friend std::ostream& operator<<(std::ostream& out, const Weapon& toPrint);
};

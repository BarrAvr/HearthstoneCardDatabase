#pragma once
#include <iostream>
#include "Spell.h"
enum key = {MANA, ATTACK, HEALTH}
class Minion : public Spell {
private:
	int attackValue;
	int healthValue;
public:
	//Constructors
	Minion();
	Minion(std::string, int, ClassType, Rarity, std::string, std::string, int, int, key);
	//Destructor
	~Minion();
	//getters
	int getAttackValue();
	int getHealthValue();
	std::string getCardType() { return "Minion"; };
	//setters
	void setAttackValue(int);
	void setHealthValue(int);

	friend std::istream& operator>>(std::istream& in, Minion& toRead);

	friend std::ostream& operator<<(std::ostream& out, const Minion& toPrint);
};
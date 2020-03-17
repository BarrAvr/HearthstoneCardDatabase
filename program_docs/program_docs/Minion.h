#pragma once
#include <iostream>
#include "Spell.h"

enum key { MANA, ATTACK, HEALTH };

class Minion : public Spell 
{
	private:
		int attackValue;
		int healthValue;
	public:
		//Constructors
		Minion();
		Minion(std::string, int, ClassType, Rarity, std::string, int, int, key);
		//Destructor
		~Minion();
		//getters
		int getAttackValue()const;
		int getHealthValue()const;
		std::string getCardType() const { return "Minion"; };
		//setters
		void setAttackValue(int);
		void setHealthValue(int);
		//misc
		void print(std::ostream& out) const;
		friend std::ostream& operator<<(std::ostream& out, const Minion& toPrint);
};
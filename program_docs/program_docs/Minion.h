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
		friend std::ostream& operator<<(std::ostream& out, const Minion& toPrint);
};
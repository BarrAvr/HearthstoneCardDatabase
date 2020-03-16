#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "HashTable.h"
#include "Spell.h"
#include "Weapon.h"
#include "Minion.h"
#include "BST.h"

using namespace std;

void addCard(fstream& file);
void searchCard(HashTable<Spell>);
void deleteCard(HashTable<Spell>);
void printHashTable(HashTable<Spell>);
void printSorted(HashTable<Spell>);
void printIndentedTree(BST<Spell>);
void cardCompare(HashTable<Spell>);
void readFileToDatabase(fstream& file);
int getCount(fstream& file);
Spell* getRandomSpell(HashTable<Spell>, Spell::Rarity);
Spell::Rarity getRandomCardRarity();
void packOpening(HashTable<Spell>);

int main() {
	int size = 67;
	string selection;
	HashTable<Spell> cardHashtable = HashTable<Spell>(size);
	BST<Spell> cardTree = BST<Spell>();
	cout << "Hearthstone Database" << endl;
	fstream inputFile;
	inputFile.open("HearthstoneCards.txt");
	readFileToDatabase(inputFile);
	
	displayMenu();
	while (true)
	{
		cout << "\nCommand: ";
		getline(cin, selection);
		if (selection == "1" || selection == "ADD") addCard(inputFile);
		else if (selection == "2" || selection == "DELETE") deleteCard(cardHashtable);
		else if (selection == "3" || selection == "SEARCH") searchCard(cardHashtable);
		else if (selection == "4" || selection == "PRINTHASH") printHashTable(cardHashtable);
		else if (selection == "5" || selection == "PRINTSORT") printSorted(cardHashtable);
		else if (selection == "6" || selection == "PRINTTREE") printIndentedTree(cardTree);
		else if (selection == "7" || selection == "COMPARE") packOpening(cardHashtable);
		else if (selection == "8" || selection == "HELP") displayMenu();
		else if (selection == "9" || selection == "EXIT") {
			cout << "Press 0 and enter to confirm you want to exit or any other key to continue" << endl;
			getline(cin, selection);
			if (selection == "0" ) break;
		}
		else {
			cout << "\nERROR: Improper command. Enter \'5\' or \'HELP\' to display menu " << endl;
		}
	}

	

	system("pause");
	return 0;



	return 0;
}

void addCard(fstream& file) {

	//Storing information from the user into tempory variables
	string name, classType, type, rarity;
	int cost;
	//We should probably add input validation
	cout << "Please enter the name for the card:" << endl;
	cin >> name;

	cout << "Please enter the Mana Cost for the card:" << endl;
	cin >> cost;

	cout << "PLease enter the Class of the card:" << endl;
	cin >> classType;

	bool finding = true;
	
	while(finding){
		cout << "Please enter the card's Type:" << endl;
		cin >> type;

		if (type == "Spell" || type == "Minion" || type == "Weapon") {
			finding = false;
		}
		else {
			cout << "Ivalid Type, please try again. " << endl;
		}
	}

	cout << "Please enter the rarity of the card:" << endl;
	cin >> rarity;


	//Take the information stored from the user and add to .CSV file
	file << name << ", "
		<< cost << ", "
		<< classType << ", "
		<< type << ", "
		<< rarity << "\n";

	//take variables and create a Card object

	if (type == "Spell") {
		//Spell s = Spell(name, cost, classType, rarity)
	}

	//add Card object to database
	cout << "Card Sucessfully added" << endl;

}

Spell* getRandomSpell(HashTable<Spell> table, Spell::Rarity rarity) {
	srand(time(0));
	int randIndex = rand() % table.getSize();
	int randDepth = rand() % table.getMaxNodes();
	Spell* randomSpell;
	for (;;) {
		if (table[randIndex] != nullptr) {
			randomSpell = table[randIndex]->find(randDepth)->getVal();
			if (randomSpell->getRarity() == rarity) break;
			else {
				randIndex = rand() % table.getSize();
				randDepth = rand() % table.getMaxNodes();
			}
		}
		else {
			randIndex = rand() % table.getSize();
			randDepth = rand() % table.getMaxNodes();
		}
		
	}
	return randomSpell;
}

Spell::Rarity getRandomCardRarity() {
	srand(time(0)); 
	int randomNum = rand()%100;
	if (randomNum <= 49) return Spell::COMMON;
	if (randomNum > 49 && randomNum <= 74) return Spell::RARE;
	if (randomNum > 74 && randomNum <= 94) return Spell::EPIC;
	if (randomNum > 94 && randomNum <= 99) return Spell::LEGENDARY;

}
void packOpening(HashTable<Spell> table)
{
	int randomGeneration;
	Spell** packArray;
	packArray[0] = getRandomSpell(table, Spell::RARE);
	packArray[1] = getRandomSpell(table, getRandomCardRarity());
	packArray[2] = getRandomSpell(table, getRandomCardRarity());
	packArray[3] = getRandomSpell(table, getRandomCardRarity());
	packArray[4] = getRandomSpell(table, getRandomCardRarity());

}

void readFileToDatabase(fstream & file) {
	string name, classType, type, rarity;
	int cost;
	string n;
	string ct;
	string t;
	string r;
	string c;
	while (getline(file, n, ',')) {
		name = n;
		getline(file, ct, ',');
		classType = ct;
		getline(file, t, ',');
		type = t;
		getline(file, r, ',');
		rarity = r;
		getline(file, c, ',');
		cost = stoi(c);
		//create person object from variables
		//add person object to database
	}
}

void displayMenu() 
{
	cout << "\nMenu: " << endl;
	cout << "Type the number OR the name of the command in caps verbatim. " << endl;
	cout << "(1) ADD - add a value to both BSTs " << endl;
	cout << "(2) DELETE - delete a value from both BSTs " << endl;
	cout << "(3) SEARCH - search for a value in both BSTs " << endl;
	cout << "(4) PRINTHASH - print all data from the hashtable " << endl;
	cout << "(5) PRINTSORT - print all data sorted by a key attribute " << endl;
	cout << "(6) PRINTTREE - print the indented BST " << endl;
	cout << "(7) PACK - Simulate a random card pack opening " << endl;
	cout << "(8) HELP - display menu once again " << endl;
	cout << "(9) EXIT - exit the program " << endl;
}


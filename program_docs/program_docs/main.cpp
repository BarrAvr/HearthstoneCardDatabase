#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <chrono>
#include "HashTable.h"
#include "Spell.h"
#include "Weapon.h"
#include "Minion.h"
#include "BST.h"

using namespace std;

void displayMenu();
void addCard(fstream& file, BST<Spell*>& tree, HashTable<Spell>& hash);
//void searchCard(HashTable<Spell>);
void deleteCard(fstream& file, BST<Spell*>& tree, HashTable<Spell>& hash);
void printHashTable(HashTable<Spell>&);
//void printSorted(HashTable<Spell>);
void printTree(BST<Spell*>&);
void printIndentedTree(BST<Spell*>);
void cardCompare(HashTable<Spell>);
void readFileToDatabase(fstream& file, BST<Spell*>& tree, HashTable<Spell>& hash);
void readDataToFile(fstream& file, BST<Spell*>& tree);
int getCount(fstream& file);
Spell* getRandomSpell(HashTable<Spell>&, Spell::Rarity);
Spell::Rarity getRandomCardRarity();
void packOpening(HashTable<Spell>&);
bool isInArray(Spell** arr, Spell* check, int size);

//TEMPORARY, BE SURE TO HAVE ONE FILE FOR FINAL BUILD
fstream outputFile;

int main() {
	int size = 50;
	string selection;
	HashTable<Spell> cardHashtable = HashTable<Spell>(size);
	BST<Spell*> cardTree = BST<Spell*>();
	cout << "Hearthstone Database" << endl;
	fstream inputFile;

	inputFile.open("input.tsv");
	readFileToDatabase(inputFile, cardTree, cardHashtable);
	while (true)
	{
		displayMenu();
		cout << "\nCommand: ";
		getline(cin, selection);
		if (selection == "1" || selection == "ADD") addCard(inputFile, cardTree, cardHashtable);
		else if (selection == "2" || selection == "DELETE") deleteCard(inputFile, cardTree, cardHashtable);
		//else if (selection == "3" || selection == "SEARCH") searchCard(cardHashtable);
		else if (selection == "4" || selection == "PRINTHASH") printHashTable(cardHashtable);
		//else if (selection == "5" || selection == "PRINTSORT") printSorted(cardHashtable);
		else if (selection == "6" || selection == "PRINTTREE") printTree(cardTree);
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
}
void printHashTable(HashTable<Spell>& table) {
	cout << table << endl;
}

void printTree(BST<Spell*>& tree) {
	string selection;
	bool wrongCommand = false;
	while (true) {
		cout << "Binary Search Tree sorted by Mana cost" << endl;
		cout << "1: Print Preorder Traversal " << endl;
		cout << "2: Print Inorder Traversal " << endl;
		cout << "3: Print Postorder Traversal " << endl;
		cout << "4: Print Breadth First Traversal " << endl;
		cout << "\nCommand: ";
		getline(cin, selection);
		if (selection == "1") tree.preOrderTraversalPrint(cout);
		else if (selection == "2") tree.inOrderTraversalPrint(cout);
		else if (selection == "3") tree.postOrderTraversalPrint(cout);
		else if (selection == "4") tree.breadthFirstTraversalPrint(cout);
		else {
			cout << "Improper command" << endl;
			wrongCommand = true;
		}
		if (wrongCommand == false) break;
	}
	
}
void addCard(fstream& file, BST<Spell*>& tree, HashTable<Spell>& hash) {

	//Storing information from the user into tempory variables
	string name, classType, type, rarity, description;
	int cost;

	//We should probably add input validation
	cout << "Please enter the name for the card:" << endl;
	cin >> name;

	cout << "Please enter the Mana Cost for the card:" << endl;
	cin >> cost;

	bool findingCT = true;
	Spell::ClassType ct;
	while (findingCT) {
		cout << "PLease enter the Class of the card:" << endl;
		cin >> classType;

		if (classType == "Neutral") {
			ct = Spell::NEUTRAL;
			findingCT = false;
		}
		else if (classType == "Druid") {
			ct = Spell::DRUID;
			findingCT = false;
		}
		else if (classType == "Hunter") {
			ct = Spell::HUNTER;
			findingCT = false;
		}
		else if (classType == "Mage") {
			ct = Spell::MAGE;
			findingCT = false;
		}
		else if (classType == "Paladin") {
			ct = Spell::PALADIN;
			findingCT = false;
		}
		else if (classType == "Priest") {
			ct = Spell::PRIEST;
			findingCT = false;
		}
		else if (classType == "Rogue") {
			ct = Spell::ROGUE;
			findingCT = false;
		}
		else if (classType == "Shaman") {
			ct = Spell::SHAMAN;
			findingCT = false;
		}
		else if (classType == "Warlock") {
			ct = Spell::WARLOCK;
			findingCT = false;
		}
		else if (classType == "Warrior") {
			ct = Spell::WARRIOR;
			findingCT = false;
		}
		else {
			cout << "Invalid Class, please try again." << endl;
		}

	}
	bool findingT = true;

	while(findingT){
		cout << "Please enter the card's Type:" << endl;
		cin >> type;

		if (type == "Spell" || type == "Minion" || type == "Weapon") {
			findingT = false;
		}
		else {
			cout << "Ivalid Type, please try again. " << endl;
		}
	}

	bool findingr = true;
	Spell::Rarity r;
	while (findingr) {
		cout << "Please enter the rarity of the card:" << endl;
		cin >> rarity;
		if (rarity == "Common") {
			r = Spell::COMMON;
			findingr = false;
		}
		else if (rarity == "Rare") {
			r = Spell::RARE;
			findingr = false;
		}
		else if (rarity == "Epic") {
			r = Spell::EPIC;
			findingr = false;
		}
		else if (rarity == "Legendary") {
			r = Spell::LEGENDARY;
			findingr = false;
		}
		else {
			cout << "Invalid rarity, please try again." << endl;
		}
	}

	cout << "Please enter the description for the card:" << endl;
	cin >> description;

	//Take the information stored from the user and add to .CSV file


	//take variables and create a Card object

	if (type == "Spell") {
		Spell* sptr;
		sptr = new Spell(name, cost, ct, r, description, Spell::MANA);
		tree.addNode(sptr);
		hash.add(sptr);
		file << name << ", "
			<< cost << ", "
			<< classType << ", "
			<< type << ", "
			<< rarity << ", "
			<< description << "\n";
	}
	else if (type == "Minion") {
		int attack;
		int defense;

		cout << "Please enter the attack value for the Minion:" << endl;
		cin >> attack;

		cout << "Please enter the health value for the Minion:" << endl;
		cin >> defense;

		Spell* mptr;
		mptr = new Minion(name, cost, ct, r, description, attack, defense, Minion::MANA);
		tree.addNode(mptr);
		hash.add(mptr);

		file << name << "\t"
			<< cost << "\t"
			<< classType << "\t"
			<< type << "\t"
			<< rarity << ", "
			<< description << "\t"
			<< attack << "\t"
			<< defense << "\n";
	}
	else if (type == "Weapon") {
		int attack;
		int defense;

		cout << "Please enter the attack value for the Weapon:" << endl;
		cin >> attack;

		cout << "Please enter the defense value for the Minion:" << endl;
		cin >> defense;

		Spell* wptr;
		wptr = new Weapon(name, cost, ct, r, description, attack, defense, Spell::MANA);
		tree.addNode(wptr);
		hash.add(wptr);

		file << name << ", "
			<< cost << ", "
			<< classType << ", "
			<< type << ", "
			<< rarity << ", "
			<< description << ", "
			<< attack << ", "
			<< defense << "\n";
	}
	cout << "Card Sucessfully added" << endl;
}

Spell* getRandomSpell(HashTable<Spell>& table, Spell::Rarity rarity) {
	srand(time(0));
	int randIndex, randDepth;
	int size = table.getSize();
	Spell* randomSpell;
	for (;;) {
		randIndex = rand() % size;
		if (table[randIndex] != nullptr) {
			randDepth = rand() % table[randIndex]->getCount();
			randomSpell = table[randIndex]->find(randDepth)->getVal();
			if (randomSpell->getRarity() == rarity) {
				size += 0;
				break; }

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
bool isInArray(Spell** arr, Spell* check, int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == check) return true;
	}
	return false;
}
void packOpening(HashTable<Spell>& table)
{
	int randomGeneration;
	string temp;
	Spell* packArray[5];
	packArray[0] = getRandomSpell(table, Spell::RARE);
	do {
		packArray[1] = getRandomSpell(table, getRandomCardRarity());
	} while (isInArray(packArray, packArray[1], 1) == true);
	do {
		packArray[2] = getRandomSpell(table, getRandomCardRarity());
	} while (isInArray(packArray, packArray[2], 2) == true);
	do {
		packArray[3] = getRandomSpell(table, getRandomCardRarity());
	} while (isInArray(packArray, packArray[3], 3) == true);
	do {
		packArray[4] = getRandomSpell(table, getRandomCardRarity());
	} while (isInArray(packArray, packArray[4], 4) == true);

	cout << "Card 1 is ..." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	cout << "..." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	cout << packArray[0] << endl;
	cout << "Card 2 is ..." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	cout << "..." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	cout << packArray[1] << endl;
	cout << "Card 3 is ..." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	cout << "..." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	cout << packArray[2] << endl;
	cout << "Card 4 is ..." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	cout << "..." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	cout << packArray[3] << endl;
	cout << "Card 5 is ..." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	cout << "..." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	cout << packArray[4] << endl;

}

void deleteCard(fstream& file, BST<Spell*>& tree, HashTable<Spell>& hash) {
	string name, classType, type, rarity, description;
	int cost;

	//We should probably add input validation
	cout << "Please enter the name for the card:" << endl;
	cin >> name;

	cout << "Please enter the Mana Cost for the card:" << endl;
	cin >> cost;

	bool findingCT = true;
	Spell::ClassType ct;
	while (findingCT) {
		cout << "PLease enter the Class of the card:" << endl;
		cin >> classType;

		if (classType == "Neutral") {
			ct = Spell::NEUTRAL;
			findingCT = false;
		}
		else if (classType == "Druid") {
			ct = Spell::DRUID;
			findingCT = false;
		}
		else if (classType == "Hunter") {
			ct = Spell::HUNTER;
			findingCT = false;
		}
		else if (classType == "Mage") {
			ct = Spell::MAGE;
			findingCT = false;
		}
		else if (classType == "Paladin") {
			ct = Spell::PALADIN;
			findingCT = false;
		}
		else if (classType == "Priest") {
			ct = Spell::PRIEST;
			findingCT = false;
		}
		else if (classType == "Rogue") {
			ct = Spell::ROGUE;
			findingCT = false;
		}
		else if (classType == "Shaman") {
			ct = Spell::SHAMAN;
			findingCT = false;
		}
		else if (classType == "Warlock") {
			ct = Spell::WARLOCK;
			findingCT = false;
		}
		else if (classType == "Warrior") {
			ct = Spell::WARRIOR;
			findingCT = false;
		}
		else {
			cout << "Invalid Class, please try again." << endl;
		}

	}
	bool findingT = true;

	while (findingT) {
		cout << "Please enter the card's Type:" << endl;
		cin >> type;

		if (type == "Spell" || type == "Minion" || type == "Weapon") {
			findingT = false;
		}
		else {
			cout << "Ivalid Type, please try again. " << endl;
		}
	}

	bool findingr = true;
	Spell::Rarity r;
	while (findingr) {
		cout << "Please enter the rarity of the card:" << endl;
		cin >> rarity;
		if (rarity == "Common") {
			r = Spell::COMMON;
			findingr = false;
		}
		else if (rarity == "Rare") {
			r = Spell::RARE;
			findingr = false;
		}
		else if (rarity == "Epic") {
			r = Spell::EPIC;
			findingr = false;
		}
		else if (rarity == "Legendary") {
			r = Spell::LEGENDARY;
			findingr = false;
		}
		else {
			cout << "Invalid rarity, please try again." << endl;
		}
	}

	cout << "Please enter the description for the card:" << endl;
	cin >> description;

	//Take the information stored from the user and add to .CSV file


	//take variables and create a Card object

	if (type == "Spell") {

		Spell sptr = Spell(name, cost, ct, r, description, Spell::MANA);
		tree.deleteNode(&sptr);
		hash.remove(sptr);
	}
	else if (type == "Minion") {
		int attack;
		int defense;

		cout << "Please enter the attack value for the Minion:" << endl;
		cin >> attack;

		cout << "Please enter the health value for the Minion:" << endl;
		cin >> defense;

		Spell mptr = Minion(name, cost, ct, r, description, attack, defense, Minion::MANA);
		tree.deleteNode(&mptr);
		hash.remove(mptr);

	}
	else if (type == "Weapon") {
		int attack;
		int defense;

		cout << "Please enter the attack value for the Weapon:" << endl;
		cin >> attack;

		cout << "Please enter the defense value for the Minion:" << endl;
		cin >> defense;

		Spell wptr = Weapon(name, cost, ct, r, description, attack, defense, Spell::MANA);
		tree.deleteNode(&wptr);
		hash.remove(wptr);
	}
	
	readDataToFile(outputFile, tree);

}


void readDataToFile(fstream& file, BST<Spell*>& tree){
	tree.inOrderTraversalPrint(file);
}

void readFileToDatabase(fstream& file, BST<Spell*>& tree, HashTable<Spell>& hash) {
	string name, classType, type, rarity;
	int cost, attack, health;
	string n;
	string ct;
	string t;
	string r;
	string c;
	string d;
	string a;
	string h;

	bool failed = false;
	while (getline(file, n, '\t')) {
		failed = false;
		name = n;

		getline(file, c, '\t');
		cost = stoi(c);

		getline(file, ct, '\t');
		Spell::ClassType clt;
		classType = ct;
		if (classType == "Neutral") {
			clt = Spell::NEUTRAL;
		}
		else if (classType == "Druid") {
			clt = Spell::DRUID;
		}
		else if (classType == "Hunter") {
			clt = Spell::HUNTER;
		}
		else if (classType == "Mage") {
			clt = Spell::MAGE;
		}
		else if (classType == "Paladin") {
			clt = Spell::PALADIN;
		}
		else if (classType == "Priest") {
			clt = Spell::PRIEST;
		}
		else if (classType == "Rogue") {
			clt = Spell::ROGUE;
		}
		else if (classType == "Shaman") {
			clt = Spell::SHAMAN;
		}
		else if (classType == "Warlock") {
			clt = Spell::WARLOCK;
		}
		else if (classType == "Warrior") {
			clt = Spell::WARRIOR;
		}
		else {
			failed = true;
		}

		getline(file, t, '\t');
		type = t;

		getline(file, r, '\t');
		rarity = r;

		Spell::Rarity rar;
		if (rarity == "Common") {
			rar = Spell::COMMON;
		}
		else if (rarity == "Rare") {
			rar = Spell::RARE;
		}
		else if (rarity == "Epic") {
			rar = Spell::EPIC;
		}
		else if (rarity == "Legendary") {
			rar = Spell::LEGENDARY;
		}
		else {
			failed = true;
		}

		getline(file, d, '\t');


		if (type == "Minion") {
			getline(file, a, '\t');
			attack = stoi(a);
			getline(file, h, '\n');
			health = stoi(h);

			if (!failed) {
				Spell* mptr;
				mptr = new Minion(name, cost, clt, rar, d, attack, health, Minion::MANA);
				tree.addNode(mptr);
				hash.add(mptr);
			}
		}
		else if (type == "Weapon") {
			getline(file, a, '\t');
			attack = stoi(a);
			getline(file, h, '\n');
			health = stoi(h);

			if (!failed) {
				Spell* wptr;
				wptr = new Weapon(name, cost, clt, rar, d, attack, health, Spell::MANA);
				tree.addNode(wptr);
				hash.add(wptr);
			}
		}
		else if (type == "Spell"){
			Spell* sptr;

			if (!failed) {
				getline(file, h, '\n');
				sptr = new Spell(name, cost, clt, rar, d, Spell::MANA);
				tree.addNode(sptr);
				hash.add(sptr);
			}
		}
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
	cout << "(6) PRINTTREE - print data from BST " << endl;
	cout << "(7) PACK - Simulate a random card pack opening " << endl;
	cout << "(8) HELP - display menu once again " << endl;
	cout << "(9) EXIT - exit the program " << endl;
}

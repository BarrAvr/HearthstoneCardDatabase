/*
	CIS 22C Final Project
	By: Santosh Lakshman, Gokul Nair, Barr Avrahamov, Noah Gutierrez
	Hearthstone Card Database 
	Program Description:
	This program sllows you to creae, search, delete and do other interactions with Hearthstone Cards
	Pseudocode:
	Read input file
	Create hashtable based on amount of cards in input file
	Loop
		Ask user for menu option
		If selection is 1
			ask user for input to add new Card
			Update file
		If selection is 2
			ask user for input to delete a Card
		If selection is 3
			ask user for input to search for a Card
		If selection is 4
			Print out hashtable
			Print out hashtable efficiency Stats
		If selection is 5
			Ask User for the type of print they want
			Print out desired traversal of Binary Search Tree
			Print out BST efficiency Stats
		If selection is 6
			Print out random Card Pack opening
		If selection is 7
			Print menu again
		If selection is 8
			Ask User to confirm they want to exit
		Exit Loop
	Exit
*/
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
template<typename T>
T validateType(T input);
void displayMenu();
void addCard(ofstream & file, BST<Spell*>& tree, HashTable<Spell>& hash);
void searchCard(HashTable<Spell>&);
void deleteCard(ofstream & file, BST<Spell*>& tree, HashTable<Spell>& hash);
void printHashTable(HashTable<Spell>&);
void printTree(BST<Spell*>&);
void readFileToDatabase(ifstream& file, BST<Spell*>& tree, HashTable<Spell>& hash);
void readDataToFile(ofstream& file, HashTable<Spell>& hash);
Spell* getRandomSpell(HashTable<Spell>&, Spell::Rarity);
Spell::Rarity getRandomCardRarity();
void packOpening(HashTable<Spell>&);
bool isInArray(Spell** arr, Spell* check, int size);
int getNumItems(ifstream&);

int main() {
	int size;
	string selection;
	ifstream inputFile;
	inputFile.open("input.tsv", ios::in);
	size = getNumItems(inputFile);
	inputFile.close();
	HashTable<Spell> cardHashtable = HashTable<Spell>(size);
	BST<Spell*> cardTree = BST<Spell*>();
	inputFile.open("input.tsv", ios::in);
	readFileToDatabase(inputFile, cardTree, cardHashtable);
	inputFile.close();
	cout << "Hearthstone Database" << endl;
	ofstream outputFile;
	while (true)
	{
		displayMenu();
		cout << "\nCommand: ";
		cin >> selection;
		if (selection == "1" || selection == "ADD") addCard(outputFile, cardTree, cardHashtable);
		else if (selection == "2" || selection == "DELETE") deleteCard(outputFile, cardTree, cardHashtable);
		else if (selection == "3" || selection == "SEARCH") searchCard(cardHashtable);
		else if (selection == "4" || selection == "PRINTHASH") printHashTable(cardHashtable);
		else if (selection == "5" || selection == "PRINTTREE") printTree(cardTree);
		else if (selection == "6" || selection == "PACK") packOpening(cardHashtable);
		else if (selection == "7" || selection == "HELP") displayMenu();
		else if (selection == "8" || selection == "EXIT") {
			cout << "Press 0 and enter to confirm you want to exit or any other key to continue" << endl;
			cin >> selection;
			if (selection == "0" ) break;
		}
		else {
			cout << "\nERROR: Improper command. Enter \'5\' or \'HELP\' to display menu " << endl;
		}
	}
	system("pause");
	return 0;
}

/*
	Reads the data in the hashtable to the database to make sure they are both in sync
	Pre: Hashtable exists
	Post: File is overwritten
*/
void readDataToFile(ofstream& file, HashTable<Spell>& hash) {
	hash.printTableInTSVFormat(file);
}

/*
	Prompts user to create a new card
	Pre: none
	Post: Spell pointer is returned
*/
Spell* createCard() {
	string selection, name, type, description, rarity, classType;
	int cost = 0;
	Spell::ClassType ct;
	Spell::Rarity r;
	bool wrongCommand;
	Spell* sptr = nullptr;

	//We should probably add input validation
	cout << "Please enter the name for the card:" << endl;
	cin >> name;

	cout << "Please enter the Mana Cost for the card:" << endl;
	cost = validateType(cost);
	cin.ignore();
	while (true) {
		wrongCommand = false;
		cout << "Please pick a number corresponding to the Class of the card:" << endl;
		cout << "1: Neutral" << endl;
		cout << "2: Druid" << endl;
		cout << "3: Hunter" << endl;
		cout << "4: Mage" << endl;
		cout << "5: Paladin" << endl;
		cout << "6: Priest" << endl;
		cout << "7: Rogue" << endl;
		cout << "8: Shaman" << endl;
		cout << "9: Warlock" << endl;
		cout << "10: Warrior" << endl;
		cout << "\nCommand: ";
		getline(cin, selection);
		if (selection == "1") ct = Spell::NEUTRAL;
		else if (selection == "2") ct = Spell::DRUID;
		else if (selection == "3") ct = Spell::HUNTER;
		else if (selection == "4") ct = Spell::MAGE;
		else if (selection == "5") ct = Spell::PALADIN;
		else if (selection == "6") ct = Spell::PRIEST;
		else if (selection == "7") ct = Spell::ROGUE;
		else if (selection == "8") ct = Spell::SHAMAN;
		else if (selection == "9") ct = Spell::WARLOCK;
		else if (selection == "10") ct = Spell::WARRIOR;
		else {
			cout << "Improper command" << endl;
			wrongCommand = true;
		}
		if (wrongCommand == false) break;
	}
	cin.ignore();
	while (true) {
		wrongCommand = false;
		cout << "Please pick a number corresponding to the Type of the card:" << endl;
		cout << "1: Spell" << endl;
		cout << "2: Minion" << endl;
		cout << "3: Weapon" << endl;
		cout << "\nCommand: ";
		getline(cin, selection);
		if (selection == "1") type = "Spell";
		else if (selection == "2") type = "Minion";
		else if (selection == "3") type = "Weapon";
		else {
			cout << "Improper command" << endl;
			wrongCommand = true;
		}
		if (wrongCommand == false) break;
	}

	cin.ignore();
	while (true) {
		wrongCommand = false;
		cout << "Please pick a number corresponding to the Rarity of the card:" << endl;
		cout << "1: Common" << endl;
		cout << "2: Rare" << endl;
		cout << "3: Epic" << endl;
		cout << "4: Legendary" << endl;

		cout << "\nCommand: ";
		
		getline(cin, selection);
		if (selection == "1") {
			r = Spell::COMMON;
			rarity = "Common";
		}
		else if (selection == "2") {
			r = Spell::RARE;
			rarity = "Rare";
		}
		else if (selection == "3") {
			r = Spell::EPIC;
			rarity = "Epic";
		}
		else if (selection == "4") {
			r = Spell::LEGENDARY;
			rarity = "Legendary";
		}
		else {
			cout << "Improper command" << endl;
			wrongCommand = true;
		}
		if (wrongCommand == false) break;
	}
	cout << "Please enter a description for the card: " << endl;
	getline(cin, description);

	if (type == "Spell") {
		description += "\t";
		description += "\t";
		sptr = new Spell(name, cost, ct, r, description, Spell::MANA);


	}
	else if (type == "Minion") {
		int attack = 0;
		int health = 0;

		cout << "Please enter the attack value for the Minion:" << endl;
		attack = validateType(attack);

		cout << "Please enter the health value for the Minion:" << endl;
		health = validateType(health);

		sptr = new Minion(name, cost, ct, r, description, attack, health, Minion::MANA);
	

	}
	else if (type == "Weapon") {
		int attack = 0;
		int durability = 0;

		cout << "Please enter the attack value for the Weapon:" << endl;
		attack = validateType(attack);

		cout << "Please enter the defense value for the Minion:" << endl;
		durability = validateType(durability);

		sptr = new Weapon(name, cost, ct, r, description, attack, durability, Spell::MANA);
	}
	return sptr;
}
/*
	Checks if a card is in the hashtable
	Pre: Hashtable exists
	Post: value is outputted
*/
void searchCard(HashTable<Spell>& hash) {
	Spell* card = createCard();
	if (hash.find(*(card)) == -1) cout << "Element not found in database" << endl;
	else cout << "Element found in database" << endl;

}

/*
	Validates if input type is the expected type for the variable
	Pre: none
	Post: value from user input is returned
*/
template<typename T>
T validateType(T input) {
	while (!(cin >> input)) {
		cout << "Wrong type. Please use the correct type \n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return input;
}
/*
	Prints out full hashtable as well as efficiency stats
	Pre: Hashtable exists
	Post: values are printed
*/
void printHashTable(HashTable<Spell>& table) {
	cout << table << endl;
	cout << "Hashtable Efficiency" << endl;
	cout << "Size of table: " << table.getNumItems() << endl;
	cout << "Load Factor: " << table.getLoadFactor() * 100 << "%\n";
	cout << "Longest Linked List length: " << table.getMaxNodes() << " nodes\n";
	cout << "Average Linked List length: " << table.getAvgNodes() << " nodes\n";
}
/*
	Prints out full Binary Search Tree in desired form as well as efficiency stats
	Pre: BST exists
	Post: values are printed
*/
void printTree(BST<Spell*>& tree) {
	
	string selection;
	bool wrongCommand = false;
	while (true) {
		cout << "Binary Search Tree sorted by Mana cost" << endl;
		cout << "1: Print Preorder Traversal " << endl;
		cout << "2: Print Inorder Traversal " << endl;
		cout << "3: Print Postorder Traversal " << endl;
		cout << "4: Print Breadth First Traversal " << endl;
		cout << "5: Print Indented Tree " << endl;
		cout << "\nCommand: ";
		cin >> selection;
		if (selection == "1") tree.preOrderTraversalPrint(cout);
		else if (selection == "2") tree.inOrderTraversalPrint(cout);
		else if (selection == "3") tree.postOrderTraversalPrint(cout);
		else if (selection == "4") tree.breadthFirstTraversalPrint(cout);
		else if (selection == "5") tree.printCardsIndent(cout);
		else {
			cout << "Improper command" << endl;
			wrongCommand = true;
		}
		if (wrongCommand == false) break;
	}
	cout << "Binary Search Tree Efficiency" << endl;
	cout << "Number of nodes in tree: " << tree.getCount() << endl;
	cout << "Average operations for inserting/searching/deleting in tree: " << tree.getAvgOps() << endl;
}

/*
	Adds a card which is specified by the user
	Pre: none
	Post: values are updated in the Hashtable, Tree, and file
*/
void addCard(ofstream & file, BST<Spell*>& tree, HashTable<Spell>& hash) {
	Spell* card = createCard();
	tree.addNode(card);
	hash.add(card);
	file.open("input.tsv", ios::out | ios::app);
	card->printToTSVFile(file);
	file.close();
	cout << "Card Sucessfully added" << endl;
}
/*
	Picks a random spell of specified rarity
	Pre: hashtable values are set
	Post: Random spell is returned
*/
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
/*
	Returns a random rarity based on probabilities from real game
	Common - 50%
	Rare - 25% 
	Epic - 20%
	Legendary - 5%
	Pre: none
	Post: value is returned
*/
Spell::Rarity getRandomCardRarity() {
	srand(time(0));
	int randomNum = rand()%100;
	if (randomNum <= 49) return Spell::COMMON;
	if (randomNum > 49 && randomNum <= 74) return Spell::RARE;
	if (randomNum > 74 && randomNum <= 94) return Spell::EPIC;
	if (randomNum > 94 && randomNum <= 99) return Spell::LEGENDARY;

}
/*
	Checks if a spell is in the array in the first size elements
	Pre: array exists
	Post: bool is returned
*/
bool isInArray(Spell** arr, Spell* check, int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == check) return true;
	}
	return false;
}
/*
	Simulates a real card pack opening from the game based on real probabilities
	Pre: hashtable exists
	Post: Pack opening is shown (dramatically)
*/
void packOpening(HashTable<Spell>& table)
{
	int randomGeneration;
	string temp;
	Spell* packArray[5];
	//One rare card guaranteed in every pack
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
	cout << *(packArray[0]) << endl;
	cout << "Card 2 is ..." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	cout << "..." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	cout << *(packArray[1]) << endl;
	cout << "Card 3 is ..." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	cout << "..." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	cout << *(packArray[2]) << endl;
	cout << "Card 4 is ..." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	cout << "..." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	cout << *(packArray[3]) << endl;
	cout << "Card 5 is ..." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	cout << "..." << endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	cout << *(packArray[4]) << endl;

}
/*
	Deletes a card from the hashtable, tree, and updates the file if the specified value is found 
	Pre: none
	Post: card is removed
*/
void deleteCard(ofstream & file, BST<Spell*>& tree, HashTable<Spell>& hash) {
	Spell* card = createCard();
	if (hash.find(*(card)) == -1) cout << "Element not found in database" << endl;
	else {
		tree.deleteNode(card);
		hash.remove(*(card));
		cout << "Element successfully deleted" << endl;
		file.open("input.tsv", ios::out | ios::trunc);
		readDataToFile(file, hash);
		file.close();
	}
}
/*
	Returns the number of cards in the file
	Pre: TSV file with values exists
	Post: int is returned
*/
int getNumItems(ifstream& file) {
	string temp;
	int items = 0;
	while (getline(file, temp, '\n')) items++;
	return items;
}
/*
	Reads in all the values from the file to the hashtable and BST
	Pre: TSV file with values exists
	Post: Hashtable and Tree values are synced with file
*/
void readFileToDatabase(ifstream& file, BST<Spell*>& tree, HashTable<Spell>& hash) {
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

		if (type == "Minion") {
			getline(file, d, '\t');
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
			getline(file, d, '\t');
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
			getline(file, d, '\n');
			Spell* sptr;
			if (!failed) {
				//getline(file, h, '\n');
				sptr = new Spell(name, cost, clt, rar, d, Spell::MANA);
				tree.addNode(sptr);
				hash.add(sptr);
			}
		}
	}
}
/*
	Outputs all menu options
	Pre: None
	Post: Values are printed
*/
void displayMenu()
{
	cout << "\nMenu: " << endl;
	cout << "Type the number OR the name of the command in caps verbatim. " << endl;
	cout << "(1) ADD - add a value to both BSTs " << endl;
	cout << "(2) DELETE - delete a value from both BSTs " << endl;
	cout << "(3) SEARCH - search for a value in both BSTs " << endl;
	cout << "(4) PRINTHASH - print all data from the hashtable " << endl;
	cout << "(5) PRINTTREE - print data from BST " << endl;
	cout << "(6) PACK - Simulate a random card pack opening " << endl;
	cout << "(7) HELP - display menu once again " << endl;
	cout << "(8) EXIT - exit the program " << endl;
}

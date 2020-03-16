#include <iostream>
#include <string>
#include <fstream>
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
<<<<<<< Updated upstream
void cardCompare(HashTable<Spell>);
void readFileToDatabase(ifstream& file);
int getCount(ifstream&);
=======
void packOpening(HashTable<Spell>);
void readFileToDatabase(ifstream file);
>>>>>>> Stashed changes

int main() {
	int size = 67;
	string selection;
	HashTable<Spell> cardHashtable = HashTable<Spell>(size);
	cout << "Hearthstone Database" << endl;
	ifstream inputFile;
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

	cout << "Please enter the card's Type:" << endl;
	cin >> type;

	cout << "PLease enter the rarity of the card:" << endl;
	cin >> rarity;


	//Take the information stored from the user and add to .CSV file
	file << name << ", "
		<< cost << ", "
		<< classType << ", "
		<< type << ", "
		<< rarity << "\n";

	//take variables and create a Card object
	//add Card object to database
	cout << "Card Sucessfully added" << endl;

}

<<<<<<< Updated upstream
void readFileToDatabase(ifstream& file) {
=======
void packOpening(HashTable<Spell>)
{

}

void readFileToDatabase(ifstream file) {
>>>>>>> Stashed changes
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


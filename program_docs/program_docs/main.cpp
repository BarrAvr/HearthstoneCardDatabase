#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void addCard(fstream& file);
void readFileToDatabase(ifstream file);

int main() {





	return 0;
}

void addCard(fstream& file) {

	//Storing information from the user into tempory variables
	string name, classType, type, rarity;
	int cost;

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

}

void readFileToDatabase(ifstream file) {
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


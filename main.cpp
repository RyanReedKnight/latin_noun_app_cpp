#include<iostream>
#include<string>
#include<stdexcept>
#include"latin_noun.h"

using std::cout;	using std::cin;	using std::endl;
using std::string;

typedef string::size_type str_sz;

int menu() {

	string nom_sng,option;

	cout << "\nType a first or second declension latin noun into the console.\n(Type \"q\" to escape.)\n" << endl;
	cin >> nom_sng;

	if (nom_sng.compare("q") == 0)
		return 0;
	else if (nom_sng.size() <= 1) {
		cout << "\nInvlid input, word must be two or more characters long.\n" << endl;
		return menu();
	}

	try {
		Latin_noun noun(nom_sng);
		cout << noun.to_string() << endl;
	}
	catch (const std::domain_error& e) {
		cout << "\nProgram can only handle first and second declension nouns.\n" << endl;
		return menu();
	}

	cout << "\nWould you like to enter another noun?\nType \"yes\" to continue or"
		" any other key to escape.\n" << endl;
	cin >> option;

	if (option.compare("Yes") == 0 || option.compare("yes") == 0)
		return menu();
	else
		return 0;
}

int main() {

	menu();
	return 0;
}
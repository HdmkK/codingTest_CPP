#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	stringstream ss("2020.01.02");
	char d = '.';
	string token;

	getline(ss, token, d);
	cout << token << endl;
	return 0;
}
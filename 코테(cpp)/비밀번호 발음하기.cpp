#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;


int main() {

	string s;

	unordered_set<char> mem{ 'a', 'e', 'i', 'o', 'u' };

	while (getline(cin, s) && s != "end") {

		bool flag1 = false;
		bool flag2 = true;
		bool flag3 = true;

		char pre_c = 0;
		int a = 0, b = 0;

		for (char c : s) {
			if (mem.count(c)) {//모음
				flag1 = true;

				a++;
				b = 0;

				if (a == 3) flag2 = false;
			}
			else {//자음
				b++;
				a = 0;

				if (b == 3) flag2 = false;
			}

			if (c != 'e' && c != 'o') {
				if (pre_c == c) flag3 = false;
			}

			pre_c = c;

		}

		if (flag1 && flag2 && flag3)
			cout << "<" << s << "> is acceptable." << endl;
		else
			cout << "<" << s << "> is not acceptable." << endl;
	}

	return 0;
}
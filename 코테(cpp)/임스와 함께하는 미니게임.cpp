#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

unordered_map<char, int> games{
	{'Y', 2},
	{'F', 3},
	{'O', 4}
};

int N;
char whatGame;
vector<string> inputs;
unordered_set<string> mem;

int main() {

	cin >> N >> whatGame;
	int answer = 0;
	cin.ignore();

	for (int i = 0; i < N; ++i) {
		string input;
		getline(cin, input);
		inputs.push_back(input);
	}

	int A = 0;
	for (string s : inputs) {
		if (mem.count(s)) continue;

		if ((++A) + 1 == games[whatGame]) {
			answer++;
			A = 0;
		}

		mem.insert(s);

	}

	cout << answer << endl;
	return 0;
}
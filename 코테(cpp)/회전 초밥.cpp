#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N, d, k, c;
vector<int> plates;

void input();


int main() {

	input();
	int answer = 0;

	unordered_map<int, int> mem;
	for (int i = 0; i < k; ++i) {
		mem[plates[i]]++;
	}
	mem[c]++;

	int kinds = mem.size();
	answer = kinds;

	for (int i = 1; i <= N - 1; ++i) {
		if (mem.count(plates[i + k - 1]) == 0 || mem[plates[i + k - 1]] == 0)
			kinds += 1;
		mem[plates[i + k - 1]]++;

		if (mem[plates[i - 1]] == 1)
			kinds -= 1;
		mem[plates[i - 1]]--;

		answer = max(answer, kinds);
	}

	cout << answer << endl;
	return 0;
}



void input() {
	cin >> N >> d >> k >> c;
	for (int i = 0; i < N; ++i) {
		int input;
		cin >> input;
		plates.push_back(input);
	}

	for (int i = 0; i < k - 1; ++i) {
		plates.push_back(plates[i]);
	}
}
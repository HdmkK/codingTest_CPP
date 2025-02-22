#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <list>
using namespace std;

void input();

int N;
vector<tuple<int, int>> people;

bool compare(const tuple<int, int>& a, const tuple<int, int>& b) {
	return get<0>(a) > get<0>(b);
}

int main() {

	input();

	sort(people.begin(), people.end(), compare);

	list<int> line;

	for (auto& [c_height, k] : people) {
		auto it = line.begin();

		if (it == line.end()) {
			line.insert(it, c_height);
			continue;
		}

		while (it != line.end() && k > 0) {
			if (*it > c_height) k--;

			it++;
		}

		line.insert(it, c_height);
	}

	for (int person : line)
		cout << person << " ";

	return 0;
}



void input() {

	cin >> N;
	for (int i = 0; i < N; ++i) {
		int input;
		cin >> input;
		people.push_back({ i + 1, input });
	}

}
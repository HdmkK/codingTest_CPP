#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int N;
vector<tuple<int, int>> inputs;


int main() {

	cin >> N;

	for (int i = 0; i < N; ++i) {
		int kg, cm;
		cin >> kg >> cm;
		inputs.push_back({ kg, cm });

	}


	for (int i = 0; i < inputs.size(); ++i) {
		int sum = 0;
		for (int j = 0; j < inputs.size(); ++j) {
			if (i == j) continue;

			if (get<0>(inputs[i]) < get<0>(inputs[j])
				&& get<1>(inputs[i]) < get<1>(inputs[j]))
				sum++;
		}
		cout << sum + 1 << " ";
	}

	return 0;
}
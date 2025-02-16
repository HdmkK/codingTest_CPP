#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;
int main() {

	int answer = 0;

	cin >> N >> M;

	vector<int> stands;

	for (int i = 0; i < M; ++i) {
		int input;
		cin >> input;
		stands.push_back(input);
	}



	answer = stands[0];

	for (int i = 0; i < M; ++i) {
		if (i + 1 < M) {
			answer = max(answer, static_cast<int>(ceil((stands[i + 1] - stands[i]) / 2.0)));
		}//다음 가로등 존재
	}

	answer = max(answer, N - stands[M - 1]);

	cout << answer << endl;

	return 0;
}
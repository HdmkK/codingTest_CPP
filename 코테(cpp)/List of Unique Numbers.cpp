#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> A;

int main() {

	long long answer = 0;

	cin >> N;
	for (int i = 0; i < N; ++i) {
		int input;
		cin >> input;
		A.push_back(input);
	}

	int start = 0, end = 0;
	bool visited[100001] = { false };

	for (; start < N; ++start) {

		while (end < N) {
			if (visited[A[end]]) break;

			visited[A[end++]] = true;
		}
		answer += end - start;

		visited[A[start]] = false;
	}

	cout << answer << endl;
	return 0;
}



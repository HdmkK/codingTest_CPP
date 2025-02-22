#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N * N; ++i) {
		int input;
		cin >> input;
		pq.push(input);

		if (pq.size() > N) pq.pop();
	}

	int answer = pq.top();
	cout << answer << endl;
	return 0;
}


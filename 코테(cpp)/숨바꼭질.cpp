#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <unordered_set>
using namespace std;

int N, K;

unordered_set<int> visited;

int main() {

	cin >> N >> K;

	queue<tuple<int, int>> q;
	q.push({ N, 0 });
	visited.insert(N);

	while (!q.empty()) {
		auto [cur, depth] = q.front();
		q.pop();

		if (cur == K) {
			cout << depth << endl;
			break;
		}

		int n_x = cur + 1;

		if (n_x <= 100000 && visited.count(n_x) == 0) {
			q.push({ n_x, depth + 1 });
			visited.insert(n_x);
		}

		n_x = 2 * cur;

		if (n_x > 0 && n_x <= 200000 && visited.count(n_x) == 0) {
			q.push({ n_x, depth + 1 });
			visited.insert(n_x);
		}

		n_x = cur - 1;

		if (n_x >= 0 && visited.count(n_x) == 0) {
			q.push({ n_x, depth + 1 });
			visited.insert(n_x);
		}

	}
	return 0;
}



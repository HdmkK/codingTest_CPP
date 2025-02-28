#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int N, M;
unordered_map<int, int> snake;
unordered_map<int, int> ladder;
vector<bool> visited(101, false);

int main() {

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		ladder[a] = b;
	}

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		snake[a] = b;
	}

	queue<tuple<int, int>> q;

	q.push({ 1, 0 });
	visited[1] = true;

	while (!q.empty()) {

		auto [cur, depth] = q.front();
		q.pop();

		if (cur == 100) {
			cout << depth << endl;
			break;
		}

		for (int i = 1; i <= 6; ++i) {
			int next;
			next = cur + i;

			if (next > 100) continue;

			if (ladder.count(next) > 0)
				next = ladder[next];
			else if (snake.count(next) > 0)
				next = snake[next];

			if (visited[next]) continue;

			q.push({ next, depth + 1 });
			visited[next] = true;
		}
	}
	return 0;
}



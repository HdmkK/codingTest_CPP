#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>


using namespace std;

int N, M;
vector<vector<int>> map;
vector<vector<int>> visited;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int BFS(int s_x, int s_y) {

	//cout << "½ÃÀÛ : " << s_x << ", " << s_y << " -> ";
	queue<tuple<int, int>> q;
	q.push({ s_x, s_y });
	visited[s_x][s_y] = 1;

	int sum = 0;

	while (!q.empty()) {
		auto [c_x, c_y] = q.front();
		q.pop();

		//cout << "(" << c_x << ", " << c_y << ") ";
		sum++;

		for (int i = 0; i < 4; ++i) {
			int n_x = c_x + dx[i];
			int n_y = c_y + dy[i];

			if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= M) continue;
			if (map[n_x][n_y] == 0) continue;
			if (visited[n_x][n_y] == 1) continue;

			q.push({ n_x, n_y });
			visited[n_x][n_y] = 1;
		}
	}

	return sum;
}

int main() {

	int answer = 0;
	int max_v = 0;

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	map.assign(N, vector<int>(M, 0));
	visited.assign(N, vector<int>(M, 0));

	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < M; ++y) {
			int input;
			cin >> input;
			map[x][y] = input;
		}
	}

	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < M; ++y) {
			if (map[x][y] == 0 || visited[x][y] == 1) continue;

			answer++;
			int result = BFS(x, y);
			max_v = max(max_v, result);
		}
	}

	cout << answer << '\n';
	cout << max_v << '\n';
	return 0;
}



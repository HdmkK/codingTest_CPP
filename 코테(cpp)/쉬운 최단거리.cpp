#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

void input();

int N, M;
vector<vector<int>> map;
vector<vector<int>> answer;
vector<vector<bool>> visited;
int s_x, s_y;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main() {

	input();

	queue<tuple<int, int, int>> q;
	q.push({ s_x, s_y, 0 });
	visited[s_x][s_y] = true;

	while (!q.empty()) {

		auto [c_x, c_y, depth] = q.front();
		q.pop();

		answer[c_x][c_y] = depth;

		for (int i = 0; i < 4; ++i) {
			int n_x = c_x + dx[i];
			int n_y = c_y + dy[i];

			if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= M) continue;
			if (map[n_x][n_y] == 0) continue;
			if (visited[n_x][n_y]) continue;

			q.push({ n_x, n_y, depth + 1 });
			visited[n_x][n_y] = true;
		}

	}

	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < M; ++y) {
			cout << answer[x][y] << " ";
		}
		cout << endl;
	}
	return 0;
}



void input() {

	cin >> N >> M;
	map.assign(N, vector<int>(M));
	answer.assign(N, vector<int>(M, -1));
	visited.assign(N, vector<bool>(M, false));

	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < M; ++y) {
			int input;
			cin >> input;
			if (input == 2) {
				s_x = x;
				s_y = y;
			}

			if (input == 0) {
				answer[x][y] = 0;
			}

			map[x][y] = input;
		}
	}

}
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int N, M;
int total;
int A[8][8];
bool visited[8][8];
vector<tuple<int, int>> virus;
int originWallCnt = 0;
int maxValue = 0;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int virusAct() {

	int cnt = 0;

	queue<tuple<int, int>> q;
	fill(&visited[0][0], &visited[0][0] + (8 * 8), false);

	for (auto& [v_x, v_y] : virus) {

		if (visited[v_x][v_y]) continue;

		q.push({ v_x, v_y });
		visited[v_x][v_y] = true;

		while (!q.empty()) {
			auto [c_x, c_y] = q.front();
			q.pop();

			cnt++;

			for (int i = 0; i < 4; ++i) {
				int n_x = c_x + dx[i];
				int n_y = c_y + dy[i];

				if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= M) continue;
				if (A[n_x][n_y] == 1) continue;
				if (visited[n_x][n_y]) continue;

				q.push({ n_x, n_y });
				visited[n_x][n_y] = true;

			}
		}
	}

	return cnt;
}

void setWall(vector<tuple<int, int>>& mem) {
	for (auto& [x, y] : mem) {
		A[x][y] = 1;
	}
}

void clearWall(vector<tuple<int, int>>& mem) {
	for (auto& [x, y] : mem) {
		A[x][y] = 0;
	}
}

int sum = 0;
void dfs(int s_x, int s_y, vector<tuple<int, int>>& mem) {

	if (mem.size() == 3) {
		sum++;

		setWall(mem);
		int ret = virusAct();
		clearWall(mem);

		int safety = total - (originWallCnt + 3 + ret);
		maxValue = max(maxValue, safety);
		return;
	}

	for (int x = s_x; x < N; ++x) {
		for (int y = 0; y < M; ++y) {
			if (x == s_x && y < s_y) continue;

			if (A[x][y] == 0) {
				mem.push_back({ x, y });

				dfs(x, y, mem);
				mem.pop_back();
			}
		}
	}
}

int main() {

	cin >> N >> M;
	total = N * M;
	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < M; ++y) {
			cin >> A[x][y];

			if (A[x][y] == 1) originWallCnt++;
			if (A[x][y] == 2) virus.push_back({ x, y });
		}
	}

	vector<tuple<int, int>> mem;
	dfs(0, 0, mem);

	cout << maxValue << endl;
	return 0;
}
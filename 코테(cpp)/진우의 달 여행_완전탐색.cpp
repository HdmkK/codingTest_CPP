#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

void input();
void dfs(int c_x, int c_y, int pre_d, int cost);

int N, M;
vector<vector<int>> board;

int INF = numeric_limits<int>::max();
int dx[] = { 1, 1, 1 };
int dy[] = { -1, 0, 1 };

int answer = INF;

int main() {

	input();

	for (int j = 0; j < M; ++j)
		dfs(0, j, -1, board[0][j]);

	cout << answer << endl;
	return 0;
}

void dfs(int c_x, int c_y, int pre_d, int cost) {
	if (c_x == N - 1) {
		answer = min(answer, cost);
		return;
	}

	for (int i = 0; i < 3; ++i) {
		if (i == pre_d) continue;

		int n_x = c_x + dx[i];
		int n_y = c_y + dy[i];

		if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= M) continue;

		dfs(n_x, n_y, i, cost + board[n_x][n_y]);
	}
}

void input() {
	cin >> N >> M;
	board.assign(N, vector<int>(M));


	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int input;
			cin >> input;
			board[i][j] = input;
		}
	}
}
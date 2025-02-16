#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void input();
int dfs(int c_x, int c_y);

int M, N;
vector<vector<int>> board;
vector<vector<int>> dp;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main() {

	input();

	cout << dfs(0, 0) << endl;


	return 0;
}

//c_x, c_y에서 M-1, N-1까지의 경로 개수를 반환
int dfs(int c_x, int c_y) {

	if (c_x == M - 1 && c_y == N - 1) return 1;
	if (dp[c_x][c_y] != -1) return dp[c_x][c_y];

	dp[c_x][c_y] = 0;
	for (int i = 0; i < 4; ++i) {
		int n_x = c_x + dx[i];
		int n_y = c_y + dy[i];

		if (n_x < 0 || n_x >= M || n_y < 0 || n_y >= N) continue;

		if (board[c_x][c_y] > board[n_x][n_y]) {
			dp[c_x][c_y] += dfs(n_x, n_y);
		}
	}

	return dp[c_x][c_y];

}

void input() {
	cin >> M >> N;
	board.assign(M, vector<int>(N));
	dp.assign(M, vector<int>(N, -1));

	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			int input;
			cin >> input;
			board[i][j] = input;
		}
	}
}
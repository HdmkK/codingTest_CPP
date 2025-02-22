#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

void input();

int N, M;
vector<vector<int>> board;
vector<vector<vector<int>>> dp;

int INF = numeric_limits<int>::max();
int dx[] = { -1, -1, -1 };
int dy[] = { -1, 0, 1 };

int answer = INF;

int main() {

	input();

	//첫행 dp 초기화
	for (int j = 0; j < M; ++j)
		for (int k = 0; k < 3; ++k)
			dp[k][0][j] = board[0][j];

	for (int x = 1; x < N; ++x) {
		for (int y = 0; y < M; ++y) {

			for (int i = 0; i < 3; ++i) {
				int p_x = x + dx[i];
				int p_y = y + dy[i];

				if (p_x < 0 || p_x >= N || p_y < 0 || p_y >= M) continue;

				for (int k = 0; k < 3; ++k) {
					if (i == k||dp[k][p_x][p_y]==INF) continue;

					dp[i][x][y] = min(dp[i][x][y], dp[k][p_x][p_y] + board[x][y]);
				}
			}
		}
	}

	
	for (int j = 0; j < M; ++j) {
		for (int k = 0; k < 3; ++k) {
			answer = min(answer, dp[k][N - 1][j]);
		}
	}

	
	cout << answer << endl;
	return 0;
}



void input() {
	cin >> N >> M;
	board.assign(N, vector<int>(M));
	dp.assign(3, vector<vector<int>>(N, vector<int>(M, INF)));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int input;
			cin >> input;
			board[i][j] = input;
		}
	}
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> cost;
vector<vector<int>> dp;
int main() {

	cin >> N;
	cost.assign(N, vector<int>(3));
	dp.assign(3, vector<int>(N, 0));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 3; ++j) {
			int input;
			cin >> input;
			cost[i][j] = input;
		}
	}

	dp[0][0] = cost[0][0];
	dp[1][0] = cost[0][1];
	dp[2][0] = cost[0][2];

	for (int x = 1; x < N; ++x) {

		dp[0][x] = min(dp[1][x - 1], dp[2][x - 1]) + cost[x][0];
		dp[1][x] = min(dp[0][x - 1], dp[2][x - 1]) + cost[x][1];
		dp[2][x] = min(dp[0][x - 1], dp[1][x - 1]) + cost[x][2];
	}

	cout << min({ dp[0][N - 1], dp[1][N - 1], dp[2][N - 1] }) << endl;

	return 0;
}
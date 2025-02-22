#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> dp;
int main() {

	cin >> N;
	dp.assign(3, vector<int>(N, 0));

	dp[0][0] = dp[1][0] = dp[2][0] = 1;

	for (int x = 1; x < N; ++x) {
		dp[0][x] = (dp[0][x - 1] + dp[1][x - 1] + dp[2][x - 1]) % 9901;
		dp[1][x] = (dp[0][x - 1] + dp[2][x - 1]) % 9901;
		dp[2][x] = (dp[0][x - 1] + dp[1][x - 1]) % 9901;
	}

	int answer = dp[0][N - 1] + dp[1][N - 1] + dp[2][N - 1];
	cout << answer % 9901 << endl;
	return 0;
}
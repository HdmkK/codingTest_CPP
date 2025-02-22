#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, K;
vector<vector<long long>> dp;
int main() {

	cin >> N >> K;
	dp.assign(K + 1, vector<long long>(N + 1, 0));

	for (int k = 1; k <= K; ++k) {
		for (int n = 0; n <= N; ++n) {
			if (k == 1 || n == 0) {
				dp[k][n] = 1;
				continue;
			}

			dp[k][n] = (dp[k][n - 1] + dp[k - 1][n]) % 1000000000;
		}
	}

	cout << dp[K][N] % 1000000000 << endl;
	return 0;
}


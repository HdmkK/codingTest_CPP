#include <iostream>
#include <vector>

using namespace std;

int TC;

int main() {

	cin >> TC;

	for (int i = 0; i < TC; ++i) {
		int n;
		cin >> n;

		vector<long long> dp(101, 0);
		dp[1] = dp[2] = dp[3] = 1;
		dp[4] = dp[5] = 2;

		for (int j = 6; j <= n; ++j) {
			dp[j] = dp[j - 1] + dp[j - 5];
		}

		cout << dp[n] << endl;
	}
	return 0;
}
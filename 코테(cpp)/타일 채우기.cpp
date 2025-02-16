#include <iostream>
#include <vector>
using namespace std;

int N;

int main() {

	cin >> N;
	vector<int> dp(N + 1, 0);

	dp[0] = 1;
	dp[2] = 3;

	for (int i = 3; i <= N; ++i) {
		if (i % 2 == 1) continue;

		dp[i] = 3 * dp[i - 2];

		for (int a = 4; i - a >= 0; a += 2) {
			dp[i] += 2 * dp[i - a];
		}
	}
	cout << dp[N] << endl;
	return 0;
}
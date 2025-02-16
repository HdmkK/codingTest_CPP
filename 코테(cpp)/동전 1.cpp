#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, k;

vector<int> coin;

int main() {

	cin >> n >> k;
	cin.ignore();

	coin.push_back(0);

	for (int i = 0; i < n; ++i) {
		int input;
		cin >> input;
		coin.push_back(input);
	}

	//배열 덮어쓰기
	vector<int> dp(k + 1, 0);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			if (j == coin[i]) {
				dp[j] = dp[j] + 1;
				continue;
			}

			if (j - coin[i] >= 0)
				dp[j] += dp[j - coin[i]];
		}
	}


	cout << dp[k] << endl;
	return 0;
}
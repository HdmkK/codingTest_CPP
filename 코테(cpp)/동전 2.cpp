#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> coin;

int main() {

	cin >> n >> k;
	coin.push_back(0);
	for (int i = 0; i < n; ++i) {
		int input;
		cin >> input;
		coin.push_back(input);
	}

	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {

			//이때는 동전 하나로 해결가능하므로 무조건 최소 동전 개수 = 1
			if (coin[i] == j) {
				dp[i][j] = 1;
				continue;
			}

			//현재 동전을 추가해선 방법이 없으므로, 현재 동전종류을 사용하지 않는 케이스(이전 : i-1)
			// 의 최소개수를 그대로 가져옴
			if (j - coin[i] < 0) {
				dp[i][j] = dp[i - 1][j];
				continue;
			}

			//둘다 0이면 현재 k를 맞출 방법이 없음 = 0
			if (dp[i - 1][j] == 0 && dp[i][j - coin[i]] == 0) {
				dp[i][j] = 0;
			}
			//현재 동전 "종류"을 제외했을 때, k를 만들 방법X -> "현재 동전"을 추가하기 전
			// 최소 동전 개수에서 + 1(현재 동전을 추가하여 k를 만드므로)
			else if (dp[i - 1][j] == 0) {
				dp[i][j] = dp[i][j - coin[i]] + 1;
			}
			//"현재 동전"을 추가해서 k를 만들 방법X -> 현재 동전 "종류"를 제외한 케이스의
			//최소 동전 개수를 그대로 가져옴
			else if (dp[i][j - coin[i]] == 0) {
				dp[i][j] = dp[i - 1][j];
			}
			//"현재 동전"을 추가해서도 k를 만들 수 있고,
			//현재 동전 종류를 제외하고도 k를 만들 수 있으므로
			// 둘 중 더 작은 케이스를 저장한다.
			else {
				dp[i][j] = min(dp[i - 1][j], dp[i][j - coin[i]] + 1);
			}
		}
	}

	if (dp[n][k] == 0)
		cout << -1 << endl;
	else
		cout << dp[n][k] << endl;


	return 0;
}
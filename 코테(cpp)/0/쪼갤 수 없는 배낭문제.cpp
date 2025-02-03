//아래 코드는 테스트 코드 입니다.
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;



int solution(vector<vector<int>> items, int weight_limit) {
	int N = items.size();
	vector<vector<int>> dp(N + 1, vector<int>(weight_limit + 1));

	for (int i = 0; i <= N; ++i) {
		for (int w = 0; w <= weight_limit; ++w) {
			if (i == 0 || w == 0) {
				dp[i][w] = 0;
				continue;
			}
			int weight = items[i - 1][0];
			int value = items[i - 1][1];

			if (weight <= w) {
				dp[i][w] = max(dp[i - 1][w], value + dp[i - 1][w - weight]);
			}
			else {
				dp[i][w] = dp[i - 1][w];
			}
		}
	}

	return dp[N][weight_limit];
}

int main()
{
	cout << solution({ {10, 60}, {20, 100}, {30, 120} }, 50) << endl; //출력값 : 27.3333

	return 0;
}
//아래 코드는 테스트 코드 입니다.
#include <iostream>
#include <vector>
using namespace std;

// 조약돌 배치 패턴에 대해 최대 가중치를 계산하는 함수
int solution(vector<vector<int>> arr) {
	int N = arr[0].size();

	vector<vector<int>> dp(4, vector<int>(N, 0));

	dp[0][0] = arr[0][0];
	dp[1][0] = arr[1][0];
	dp[2][0] = arr[2][0];
	dp[3][0] = arr[0][0] + arr[2][0];

	for (int i = 1; i < N; ++i) {
		dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]) + arr[0][i];
		dp[1][i] = max({ dp[0][i - 1], dp[2][i - 1], dp[3][i - 1] }) + arr[1][i];
		dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]) + arr[2][i];
		dp[3][i] = dp[1][i - 1] + arr[0][i] + arr[2][i];
	}

	return max({dp[0][N-1], dp[1][N - 1] , dp[2][N - 1] ,dp[3][N - 1] });
}

int main()
{
	cout << solution({ {1, 3, 3, 2}, {2, 1, 4, 1}, {1, 5, 2, 3} }) << endl; //출력값 : 19
	cout << solution({ {1, 7, 13, 2, 6}, {2, -4, 2, 5, 4}, {5, 3, 5, -3, 1} }) << endl; //출력값 : 32

	return 0;
}
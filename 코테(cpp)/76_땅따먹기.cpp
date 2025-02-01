#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int N = land.size();
    vector<vector<int>> dp(N, vector<int>(4, 0));

    for (int i = 0; i < 4; ++i) {
        dp[0][i] = land[0][i];
    }

    for (int i = 1; i < N; ++i) {
        dp[i][0] = max({ dp[i - 1][1], dp[i - 1][2], dp[i - 1][3] }) + land[i][0];
        dp[i][1] = max({ dp[i - 1][0], dp[i - 1][2], dp[i - 1][3] }) + land[i][1];
        dp[i][2] = max({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][3] }) + land[i][2];
        dp[i][3] = max({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2] }) + land[i][3];
    }

    return *max_element(dp[N - 1].begin(), dp[N - 1].end());
}
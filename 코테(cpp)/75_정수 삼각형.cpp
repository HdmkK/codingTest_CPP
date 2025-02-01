#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int N = triangle.size();
    vector<vector<int>> dp(N);
    for (int i = 0; i < N; ++i) {
        dp[i] = vector<int>(i + 1);

        //�ǲ����
        if (i == 0) {
            dp[0][0] = triangle[0][0];
            continue;
        }

        //�糡
        dp[i][0] = triangle[i][0] + dp[i - 1][0];
        dp[i][i] = triangle[i][i] + dp[i - 1][i - 1];

        //�߰� ����� �ִ� ����
        for (int j = 1; j < i; ++j) {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
        }
    }

    return *max_element(dp[N - 1].begin(), dp[N - 1].end());
}
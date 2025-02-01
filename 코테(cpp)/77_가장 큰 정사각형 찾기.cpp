#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int M = board.size();
    int N = board[0].size();

    vector<vector<int>> dp(M, vector<int>(N, 0));

    for (int x = 0; x < M; ++x) {
        for (int y = 0; y < N; ++y) {
            if (x == 0 || y == 0) {
                dp[x][y] = board[x][y];
                answer = max(answer, dp[x][y]);
                continue;
            }

            if (board[x][y] == 0) continue;

            dp[x][y] = min({ dp[x][y - 1], dp[x - 1][y - 1], dp[x - 1][y] }) + 1;
            answer = max(answer, dp[x][y] * dp[x][y]);
        }
    }

    return answer;
}
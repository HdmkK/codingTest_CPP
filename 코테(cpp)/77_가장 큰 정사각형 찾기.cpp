#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int M = board.size();
    int N = board[0].size();

    if (M == 1 || N == 1) return 1;

    for (int x = 1; x < M; ++x) {
        for (int y = 1; y < N; ++y) {
            if (board[x][y] == 0) continue;

            board[x][y] = min({ board[x - 1][y - 1], board[x - 1][y], board[x][y - 1] }) + 1;
            answer = max(answer, board[x][y]);
        }
    }

    return answer * answer;
}
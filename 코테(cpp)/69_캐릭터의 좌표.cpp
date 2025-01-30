#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer;

    //편의를 위해 x, y를 반대로 생각 -> 마지막에 y,x를 반환하면 됨.
    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };

    int M = (board[0] - 1) / 2;
    int N = (board[1] - 1) / 2;
    unordered_map<string, int> dr{
        {"up", 0},
        {"down", 1},
        {"left", 2},
        {"right", 3}
    };

    int x = 0, y = 0;
    for (string cmd : keyinput) {

        int n_x = x + dx[dr[cmd]];
        int n_y = y + dy[dr[cmd]];

        if (-N <= n_x && n_x <= N && -M <= n_y && n_y <= M) {
            x = n_x;
            y = n_y;
        }
    }

    return { y, x };
}
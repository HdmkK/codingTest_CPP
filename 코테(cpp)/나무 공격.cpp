#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(int argc, char** argv)
{
    int N, M;
    int monsterSum = 0;
    cin >> N >> M;

    vector<vector<int>> board(N + 1, vector<int>(M + 1));
    unordered_map<int, int> mem;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                monsterSum++;
                mem[i]++;
            }

        }
    }

    vector<vector<int>> attacks(2);
    for (int i = 0; i < 2; ++i) {
        int L, R;
        cin >> L >> R;

        for (int row = L; row <= R; ++row) {
            if (mem[row] > 0) {
                mem[row]--;
                monsterSum--;
            }
        }
    }

    cout << monsterSum << endl;
    return 0;
}
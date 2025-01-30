#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    const int N = board.size();
    vector<stack<int>> stks(N);
    stack<int> bowl;

    //보드 스택 초기화(넣는 방법 주의)
    for (int i = 0; i < N; ++i) {
        for (int j = N - 1; j > -1; --j) {
            cout << board[j][i] << " ";
            if (board[j][i] == 0)
                continue;
            stks[i].push(board[j][i]);
        }
        cout << endl;
    }

    cout << "====" << endl;



    //차례대로 작업을 수행
    for (int mv : moves) {

        auto& stk = stks[mv - 1];

        if (stk.empty())
            continue;

        int cur_picked = stk.top();

        cout << mv << " -> " << cur_picked << endl;
        stk.pop();

        //바구니(스택)에 담아서 처리
        if (!bowl.empty() && bowl.top() == cur_picked) {
            bowl.pop();
            answer += 2;
            continue;
        }

        bowl.push(cur_picked);
    }

    return answer;
}
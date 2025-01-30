#include <string>
#include <vector>
#include <array>
#include <iostream>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    const int N = board.size();

    vector<int> cursors(N, N); // 각 열에 대해서 크레인이 다음에 뽑을 인형의 행번호를 저장
    stack<int> st; //바구니

    //cursors에 1 ~ N열에 대해서 가장 위에 있는 인형의 행번호를 저장
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[j][i] != 0)
            {
                cursors[i] = j;
                break;
            }
        }
    }

    int move_size = moves.size();

    //moves에 따라 인형을 바구니(stack) 옮기는 작업
    for (int i = 0; i < move_size; ++i) {

        int cur_move = moves[i] - 1;//이번 move(인덱스 고려해서 -1)

        //현재 열에 대해서 인형을 바닥까지 뽑았다면 무시
        if (cursors[cur_move] == N)
            continue;

        //인형 pick
        int cur_picked = board[cursors[cur_move]++][cur_move];

        //바구니에서 짝을 지었다면 anwer증가
        //짝이 없다면 push
        if (!st.empty() && st.top() == cur_picked) {
            st.pop();
            answer += 2;
        }
        else {
            st.push(cur_picked);
        }

    }

    return answer;
}
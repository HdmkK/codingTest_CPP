#include <string>
#include <vector>
#include <array>
#include <iostream>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    const int N = board.size();

    vector<int> cursors(N, N); // �� ���� ���ؼ� ũ������ ������ ���� ������ ���ȣ�� ����
    stack<int> st; //�ٱ���

    //cursors�� 1 ~ N���� ���ؼ� ���� ���� �ִ� ������ ���ȣ�� ����
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

    //moves�� ���� ������ �ٱ���(stack) �ű�� �۾�
    for (int i = 0; i < move_size; ++i) {

        int cur_move = moves[i] - 1;//�̹� move(�ε��� ����ؼ� -1)

        //���� ���� ���ؼ� ������ �ٴڱ��� �̾Ҵٸ� ����
        if (cursors[cur_move] == N)
            continue;

        //���� pick
        int cur_picked = board[cursors[cur_move]++][cur_move];

        //�ٱ��Ͽ��� ¦�� �����ٸ� anwer����
        //¦�� ���ٸ� push
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
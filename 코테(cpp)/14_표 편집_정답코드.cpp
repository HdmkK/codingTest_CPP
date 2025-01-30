#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";

    vector<int> up(n + 2);
    vector<int> down(n + 2);
    stack<int> st;

    //up, down�迭 �ʱ�ȭ
    for (int i = 0; i < n + 2; ++i) {
        up[i] = i - 1;
        down[i] = i + 1;
        //cout << up[i] << ", " << down[i] << endl;
    }

    //�ʱⰪ ����
    k++;

    //����� ���ʷ� ����
    for (int i = 0; i < cmd.size(); ++i) {

        if (cmd[i][0] == 'U') {
            int X = stoi(cmd[i].substr(2));
            //cout << X << endl;

            //X�� ���� �̵�
            for (int j = 0; j < X; ++j) {
                k = up[k];
            }
        }

        if (cmd[i][0] == 'D') {
            int X = stoi(cmd[i].substr(2));

            //X�� ���� �̵�
            for (int j = 0; j < X; ++j) {
                k = down[k];
            }
        }

        if (cmd[i][0] == 'C') {
            down[up[k]] = down[k];
            up[down[k]] = up[k];

            st.push(k);

            if (down[k] == n + 1)
                k = up[k];
            else
                k = down[k];
        }

        if (cmd[i][0] == 'Z') {
            int last_row = st.top();
            st.pop();

            down[up[last_row]] = last_row;
            up[down[last_row]] = last_row;
        }
    }

    //ó���� answer�� ���X�� �ʱ�ȭ�ϰ�
    //�̵��ϸ鼭 O�� ä���.
    for (int i = 0; i < n; ++i) {
        answer += "X";
    }

    k = down[0];
    while (down[k] != n + 2) {
        answer[k - 1] = 'O';
        k = down[k];
    }


    return answer;
}
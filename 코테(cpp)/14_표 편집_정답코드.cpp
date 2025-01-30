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

    //up, down배열 초기화
    for (int i = 0; i < n + 2; ++i) {
        up[i] = i - 1;
        down[i] = i + 1;
        //cout << up[i] << ", " << down[i] << endl;
    }

    //초기값 조정
    k++;

    //명령을 차례로 실행
    for (int i = 0; i < cmd.size(); ++i) {

        if (cmd[i][0] == 'U') {
            int X = stoi(cmd[i].substr(2));
            //cout << X << endl;

            //X번 위로 이동
            for (int j = 0; j < X; ++j) {
                k = up[k];
            }
        }

        if (cmd[i][0] == 'D') {
            int X = stoi(cmd[i].substr(2));

            //X번 위로 이동
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

    //처음엔 answer를 모두X로 초기화하고
    //이동하면서 O를 채운다.
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
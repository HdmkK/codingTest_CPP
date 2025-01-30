#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

string change(int n) {
    stack<int> mem;
    string result = "";

    //������ ����� ������ ������ ���ڿ��� ��ȯ
    while (n > 1) {
        mem.push(n % 2);
        n /= 2;
    }
    mem.push(n);

    //���ÿ��� ���� ���ڿ� �ϼ�
    while (!mem.empty()) {
        result += to_string(mem.top());
        mem.pop();
    }

    return result;
}

vector<int> solution(string s) {
    vector<int> answer;
    int round = 1;
    int cnt = 0;

    while (s.size() > 1) {

        //0�� ������ ���ڿ��� ���Ѵ�.
        string tmp_s;
        for (char c : s) {
            if (c == '1') tmp_s += "1";
        }

        //���ŵ� 0�� ������ ����
        cnt += s.size() - tmp_s.size();
        int n = tmp_s.size();

        //���� ������ ������ ���ڿ��� ��ȯ
        s = change(n);
        round++;
    }

    return vector<int>{--round, cnt};
}
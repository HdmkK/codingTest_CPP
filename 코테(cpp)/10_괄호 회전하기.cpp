#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

unordered_map<char, char> mem{
    make_pair(')', '('),
    make_pair('}', '{'),
    make_pair(']', '[')
};

bool valid(string& s, int start) {
    stack<char> st;

    for (int offset = 0; offset < s.length(); ++offset) {

        int idx = (start + offset) % s.length();
        if (mem.find(s[idx]) != mem.end() && mem.size() > 0 && mem[s[idx]] == st.top()) {
            st.pop();
            continue;
        }
        st.push(s[idx]);
    }

    return st.size() == 0;
}

int solution(string s) {
    int answer = 0;

    //ȸ��(������ ȸ��X, �����ε����� �ٸ��� ����)
    for (int start = 0; start < s.length(); ++start) {
        if (valid(s, start))
            answer++;
    }

    return answer;
}
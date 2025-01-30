#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = -1;

    stack<char> st;

    for (auto ch : s) {
        if (!st.empty() && st.top() == ch) {
            st.pop();
            continue;
        }

        st.push(ch);
    }

    return st.empty();
}
#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

string change(int n) {
    stack<int> mem;
    string result = "";

    //스택을 사용해 정수를 이진수 문자열로 변환
    while (n > 1) {
        mem.push(n % 2);
        n /= 2;
    }
    mem.push(n);

    //스택에서 꺼내 문자열 완성
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

        //0을 제거한 문자열을 구한다.
        string tmp_s;
        for (char c : s) {
            if (c == '1') tmp_s += "1";
        }

        //제거된 0의 갯수를 누적
        cnt += s.size() - tmp_s.size();
        int n = tmp_s.size();

        //길이 정수를 이진수 문자열로 변환
        s = change(n);
        round++;
    }

    return vector<int>{--round, cnt};
}
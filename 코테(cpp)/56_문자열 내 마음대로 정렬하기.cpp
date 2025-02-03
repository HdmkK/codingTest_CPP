#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int idx;

bool compare(const string& a, const string& b) {
    if (a[idx] == b[idx]) return a < b;
    return a[idx] < b[idx];
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;

    for (string s : strings) {
        answer.push_back(s);
    }

    idx = n;
    sort(answer.begin(), answer.end(), compare);
    return answer;
}
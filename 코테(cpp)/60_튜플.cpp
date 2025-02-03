#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>
using namespace std;

bool compare(const vector<int>& a, const vector<int>& b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;

    vector<vector<int>> mem;
    int idx = 0;
    int in_set = 0;
    string buf = "";
    for (int i = 1; i < s.length() - 1; ++i) {
        char c = s[i];

        if (c == '{') {
            in_set = 1;
            mem.push_back(vector<int>());
        }
        else if (c == ',') {
            if (in_set == 0) continue;

            mem[idx].push_back(stoi(buf));
            buf = "";
        }
        else if (c == '}') {
            mem[idx].push_back(stoi(buf));
            buf = "";
            idx++;
            in_set = 0;
        }
        else {
            buf += c;
        }
    }

    sort(mem.begin(), mem.end(), compare);
    unordered_set<int> check;

    for (auto lst : mem) {
        for (int num : lst) {
            if (check.find(num) != check.end()) continue;

            answer.push_back(num);
            check.insert(num);
        }
    }

    return answer;
}
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<string, int> mem;

bool compare(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}

void combination(string& str, string& cur, int start, int k) {

    if (cur.length() == k) {
        mem[cur]++;
        return;
    }

    for (int i = start; i < str.length(); ++i) {
        cur += str[i];
        combination(str, cur, i + 1, k);
        cur.pop_back();
    }

}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    //정렬을 해줘야 이후 조합을 구할 때 엉키지 않음.
    for (string& order : orders)
        sort(order.begin(), order.end());

    for (int type : course) {
        for (string order : orders) {
            string cur = "";
            combination(order, cur, 0, type);
        }

        vector<pair<string, int>> mem_vector(mem.begin(), mem.end());
        mem.clear();
        sort(mem_vector.begin(), mem_vector.end(), compare);

        int std = mem_vector[0].second;
        for (auto e : mem_vector) {
            if (e.second < std) break;
            if (e.second == 1) break;

            answer.push_back(e.first);
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}
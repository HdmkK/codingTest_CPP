#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

class Compare
{
public:
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }
};

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<int, int> mem;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> q;

    unordered_set<int> size_types;
    for (int t : tangerine) {
        mem[t] += 1;
    }

    for (auto e : mem) {
        q.push({ e.first, e.second });
    }


    while (k > 0) {
        auto e = q.top();
        q.pop();

        int key = e.first;
        int value = e.second;

        if (k >= value)
            k -= value;
        else
            k = 0;

        size_types.insert(key);

    }

    //개수세기
    return size_types.size();
}
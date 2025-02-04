#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_map<int, int> mem;

    for (int num : nums) {
        mem[num]++;
    }

    vector<pair<int, int>> sorted(mem.begin(), mem.end());
    sort(sorted.begin(), sorted.end(), compare);

    if (nums.size() / 2 < mem.size()) return nums.size() / 2;
    else return mem.size();

}
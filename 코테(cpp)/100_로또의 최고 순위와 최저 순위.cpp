#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    unordered_set<int> mem;

    for (int num : win_nums) {
        mem.insert(num);
    }

    //ÃÖ°í
    int cnt = 0;
    for (int num : lottos) {
        if (num == 0) {
            cnt++;
            continue;
        }

        if (mem.count(num) > 0) cnt++;
    }
    int max_rate = (cnt == 0) ? 6 : (7 - cnt);

    cnt = 0;
    for (int num : lottos) {
        if (mem.count(num) > 0) cnt++;
    }
    int min_rate = (cnt == 0) ? 6 : (7 - cnt);
    return { max_rate, min_rate };
}
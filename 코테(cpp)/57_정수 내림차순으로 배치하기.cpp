#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> mem;
    while (n > 0) {
        mem.push_back(n % 10);
        n /= 10;
    }

    sort(mem.begin(), mem.end());
    for (int i = 0; i < mem.size(); ++i) {
        answer += mem[i] * pow(10, i);
    }
    return answer;
}
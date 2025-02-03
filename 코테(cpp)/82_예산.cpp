#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;

    sort(d.begin(), d.end());
    for (int v : d) {
        if (budget >= v) {
            answer += 1;
            budget -= v;
        }
    }
    return answer;
}
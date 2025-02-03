#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

int dp[101][10000001] = { -1 };

int solve(int n, int budget, vector<int>& d) {
    int max_v = 0;

    if (n == 0 || budget == 0) {
        dp[n][budget] = 0;
        return 0;
    }

    if (dp[n - 1][budget] == -1) {
        dp[n - 1][budget] = solve(n - 1, budget, d);
    }
    max_v = dp[n - 1][budget];

    if (d[n - 1] <= budget) {
        if (dp[n - 1][budget - d[n - 1]] == -1)
            dp[n - 1][budget - d[n - 1]] = solve(n - 1, budget - d[n - 1], d);
        max_v = max(max_v, dp[n - 1][budget - d[n - 1]] + 1);
    }

    return max_v;

}

int solution(vector<int> d, int budget) {


    int answer = 0;
    answer = solve(d.size(), budget, d);
    return answer;
}
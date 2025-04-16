#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;

    int num = info.size();

    vector<vector<int>> dp(num + 1, vector<int>(m, 0));

    for (int x = 1; x <= num; ++x) {
        for (int y = 0; y < m; ++y) {

            dp[x][y] = dp[x - 1][y] + info[x - 1][0];

            if (y >= info[x - 1][1])
                dp[x][y] = min(dp[x][y], dp[x - 1][y - info[x - 1][1]]);
        }
    }

    int min_v = *min_element(dp[num].begin(), dp[num].end());
    if (min_v >= n)
        return -1;
    else
        return min_v;
}
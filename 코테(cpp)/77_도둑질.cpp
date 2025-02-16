#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int N = money.size();
    vector<int> dp1(N, 0);

    dp1[0] = money[0];
    dp1[1] = money[0];
    for (int i = 2; i < N - 1; ++i)
        dp1[i] = max(dp1[i - 2] + money[i], dp1[i - 1]);

    vector<int> dp2(N, 0);

    dp2[1] = max(money[1], 0);
    for (int i = 2; i < N; ++i)
        dp2[i] = max(dp2[i - 2] + money[i], dp2[i - 1]);

    return max(dp1[N - 2], dp2[N - 1]);
}
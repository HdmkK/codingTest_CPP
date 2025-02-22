#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int i, j;
vector<int> A;
vector<int> dp;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	A.assign(N + 1, 0);
	dp.assign(N + 1, 0);

	for (int i = 1; i <= N; ++i) {
		int input;
		cin >> input;
		A[i] = input;
		dp[i] = dp[i - 1] + A[i];
	}

	for (int k = 0; k < M; ++k) {
		cin >> i >> j;
		int answer = dp[j] - dp[i - 1];
		cout << answer << '\n';
	}

	return 0;
}
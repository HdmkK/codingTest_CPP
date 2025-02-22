#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <limits>
#include <stack>
using namespace std;

int N;
vector<int> dp;

int main() {

	cin >> N;
	dp.assign(N + 1, 0);

	for (int i = 2; i <= N; ++i) {
		dp[i] = dp[i - 1] + 1;

		if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
	}

	cout << dp[N] << endl;

	vector<int> arr;
	arr.push_back(N);
	int temp = dp[N] - 1;
	int now = N;

	for (int i = N; i >= 1; --i) {
		if (dp[i] == temp && (i + 1 == now || i * 2 == now || i * 3 == now)) {
			arr.push_back(i);
			temp--;
			now = i;
		}
	}

	for (int e : arr)
		cout << e << " ";
	return 0;
}
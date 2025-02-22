

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
vector<int> A;
vector<int> dp;
int main() {

	cin >> n;
	A.assign(n, 0);
	dp.assign(n, 1);

	for (int i = 0; i < n; ++i) {
		int input;
		cin >> input;
		A[i] = input;
	}

	dp[0] = 1;
	for (int i = 1; i < n; ++i) {
		int max_v = 0;
		for (int j = 0; j < i; ++j) {
			if (A[j] >= A[i]) continue;

			max_v = max(max_v, dp[j]);
		}
		dp[i] = max_v + 1;
	}

	int answer = 0;
	for (int i = 0; i < n; ++i)
		answer = max(answer, dp[i]);
	cout << answer << endl;
	return 0;
}


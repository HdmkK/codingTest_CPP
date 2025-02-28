#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include <unordered_map>
#include <limits>
using namespace std;

int N, D;
int INF = numeric_limits<int>::max();
unordered_map<int, vector<tuple<int, int>>> road;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> D;
	vector<int> dp(10001, INF);

	dp[0] = 0;

	for (int i = 0; i < N; ++i) {
		int start, end, cost;
		cin >> start >> end >> cost;
		road[start].push_back({ end, cost });
	}

	for (int x = 0; x <= D; ++x) {

		if (x > 0)
			dp[x] = min(dp[x], dp[x - 1] + 1);

		for (auto [end, cost] : road[x])
			dp[end] = min(dp[end], dp[x] + cost);



	}

	cout << dp[D] << endl;
	return 0;
}



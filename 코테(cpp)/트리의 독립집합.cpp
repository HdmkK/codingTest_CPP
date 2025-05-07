#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;

void input();
int MIST(int rootNode);
void tracing(int rootNode, bool prevInclude);

int N;
unordered_map<int, unordered_set<int>> adjList;
unordered_map<int, int> weights;
unordered_set<int> visited;
vector<vector<int>> dp;//각 노드에 대해서 포함/미포함 할 때 최대독립집합
vector<int> mistNodes;

int main() {

	input();
	cout << MIST(1) << endl;
	visited.clear();
	tracing(1, false);
	sort(mistNodes.begin(), mistNodes.end());
	for (int e : mistNodes)
		cout << e << " ";
	return 0;
}

int MIST(int rootNode) {

	visited.insert(rootNode);

	dp[rootNode][0] = 0;
	dp[rootNode][1] = weights[rootNode];

	for (int nextNode : adjList[rootNode]) {

		if (visited.count(nextNode)) continue;

		dp[rootNode][0] += MIST(nextNode);
		dp[rootNode][1] += dp[nextNode][0];
	}

	return max(dp[rootNode][0], dp[rootNode][1]);
}

void tracing(int rootNode, bool prevInclude) {

	visited.insert(rootNode);
	bool includeFlag = false;

	if (dp[rootNode][1] > dp[rootNode][0] && !prevInclude) {
		mistNodes.push_back(rootNode);
		includeFlag = true;
	}

	for (int next : adjList[rootNode]) {
		if (visited.count(next)) continue;

		tracing(next, includeFlag);
	}
}

void input() {
	cin >> N;
	dp.assign(N + 1, vector<int>(2, 0));
	for (int i = 1; i <= N; ++i)
		cin >> weights[i];

	for (int i = 1; i < N; ++i) {
		int u, v;
		cin >> u >> v;
		adjList[u].insert(v);
		adjList[v].insert(u);
	}
}


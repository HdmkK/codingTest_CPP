#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <tuple>
#include <unordered_map>
using namespace std;

int N, D;
unordered_map<int, vector<tuple<int, int>>> adjList;
unordered_map<int, int> cost;
class Compare
{
public:
	bool operator() (const tuple<int, int>& a, const tuple<int, int>& b) {
		return get<1>(a) > get<1>(b);
	}
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> D;

	for (int x = 0; x < D; ++x)
		adjList[x].push_back({ x + 1, 1 });

	for (int i = 0; i < N; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adjList[u].push_back({ v, w });
	}

	priority_queue<tuple<int, int>, vector<tuple<int, int>>, Compare > pq;
	pq.push({ 0, 0 });

	while (!pq.empty()) {
		auto [cur_node, cur_cost] = pq.top();
		pq.pop();

		if (cost.count(cur_node) == 0)
			cost[cur_node] = cur_cost;

		for (auto [next_node, weight] : adjList[cur_node]) {
			if (cost.count(next_node) > 0) continue;

			pq.push({ next_node, cur_cost + weight });
		}

	}

	cout << cost[D] << endl;
	return 0;
}



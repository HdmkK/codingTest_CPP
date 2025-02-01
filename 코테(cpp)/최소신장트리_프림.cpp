#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <queue>
using namespace std;

unordered_map<int, vector<tuple<int, int>>> adjList;

void makeAdjList(vector<vector<int>>& info) {
	for (auto& lst : info) {
		int u = lst[0];
		int v = lst[1];
		int w = lst[2];
		adjList[u].push_back({ v, w });
		adjList[v].push_back({ u, w });
	}
}

class Compare
{
public:
	bool operator() (const tuple<int, int, int> a, const tuple<int, int, int> b) {
		return get<2>(a) > get<2>(b);
	}
};

void print_graph(unordered_map<int, vector<tuple<int, int>>>& mst_adjList) {

	for (auto& edge : mst_adjList) {
		auto& u = edge.first;
		auto& lst = edge.second;
		for (auto& [v, w] : lst) {
			cout << "(" << u << ", " << v << ", " << w << ")" << endl;
		}
	}
}

void solution(vector<vector<int>>& info) {

	makeAdjList(info);

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Compare> pq;
	unordered_set<int> mst_node;
	unordered_map<int, vector<tuple<int, int>>> mst_adjList;

	int start = 1;
	mst_node.insert(start);

	//처음에 시작노드를 기준으로 주변 간선 정보를 우선순위큐에 밀어넣음.
	for (auto& [v, w] : adjList[start]) {
		pq.push({ start, v, w });
	}

	while (!pq.empty()) {

		auto [u, v, w] = pq.top();
		pq.pop();

		if (mst_node.count(v) == 0) {
			mst_adjList[u].push_back({ v, w });
			mst_adjList[v].push_back({ u, w });
			mst_node.insert(v);

			if (mst_node.size() == adjList.size()) break;
		}

		for (auto& [n_v, n_w] : adjList[v]) {
			if (mst_node.count(n_v) > 0) continue;

			pq.push({ v, n_v, n_w });
		}
	}

	print_graph(mst_adjList);

}

int main() {
	vector<vector<int>> info = {
		{2,3,2},
		{3,6,3},
		{3,5,4},
		{2,6,5},
		{4,5,5},
		{3,4,6},
		{1,4,7},
		{2,4,8},
		{1,2,9}
	};

	solution(info);
	
	return 0;
}
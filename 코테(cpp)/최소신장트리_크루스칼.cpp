#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <queue>

#include <algorithm>
using namespace std;

bool compare(const vector<int>& a, const vector<int>& b) {
	return a[2] < b[2];
}

void print_graph(unordered_map<int, vector<tuple<int, int>>>& mst_adjList) {

	for (auto& edge : mst_adjList) {
		auto& u = edge.first;
		auto& lst = edge.second;
		for (auto& [v, w] : lst) {
			cout << "(" << u << ", " << v << ", " << w << ")" << endl;
		}
	}
}

void solution(vector<vector<int>>& info, int n) {

	unordered_map<int, vector<tuple<int, int>>> mst_adjList;

	//간선 정보가 주어졌을 때 바로 가중치를 기준으로 오름차순 정렬
	sort(info.begin(), info.end(), compare);

	for (auto lst : info) {
		int u = lst[0];
		int v = lst[1];
		int w = lst[2];

		//사이클을 만든다면 해당 간선 패스
		if (mst_adjList.count(u) > 0 && mst_adjList.count(v)) continue;

		mst_adjList[u].push_back({ v, w });
		mst_adjList[v].push_back({ u, w });

		if (mst_adjList.size() == n) break;
		
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
	int n = 6;
	solution(info, n);

	return 0;
}
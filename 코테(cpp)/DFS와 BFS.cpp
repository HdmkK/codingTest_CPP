#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

void input();
void dfs(int node);
void bfs(int node);
int N, M, V;

unordered_map<int, vector<int>> adjList;
unordered_set<int> visited;

int main() {

	input();

	for (auto& e : adjList)
		sort(e.second.begin(), e.second.end());


	dfs(V);
	cout << endl;
	visited.clear();
	bfs(V);
	return 0;
}

void bfs(int start_node) {

	queue<int> q;
	q.push(start_node);
	visited.insert(start_node);

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		cout << node << " ";
		for (int next_node : adjList[node]) {
			if (visited.count(next_node) > 0) continue;

			q.push(next_node);
			visited.insert(next_node);
		}
	}


}

void dfs(int node) {

	visited.insert(node);
	cout << node << " ";

	for (int next_node : adjList[node]) {
		if (visited.count(next_node) > 0) continue;

		dfs(next_node);
	}

}

void input() {
	cin >> N >> M >> V;
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

}
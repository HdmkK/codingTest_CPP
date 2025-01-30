#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, vector<int>> adjList;
unordered_set<int> visited;
vector<int> result;

void BFS(int start) {
	
	queue<int> my_q;
	my_q.push(start);
	visited.insert(start);

	while (!my_q.empty()) {

		int cur_node = my_q.front();
		my_q.pop();

		//방문
		result.push_back(cur_node);

		for (int next : adjList[cur_node]) {

			//이미 방문?
			if (visited.find(next) != visited.end())
				continue;

			my_q.push(next);
			visited.insert(next);
		}
	}
	
	
}

vector<int> solution(vector<pair<int, int>> graph, int start) {

	//인접리스트 생성
	for (auto edge : graph) {
		int u = edge.first;
		int v = edge.second;
		adjList[u].push_back(v);
	}

	//너비우선탐색
	BFS(start);

	return result;
}
int main() {

	vector<pair<int, int>> graph{
		//{1,2},{1,3},{2,4},{2,5},{3,6},{3,7},{4,8},{5,8},{6,9},{7,9}
		{0,1},{1,2},{2,3},{3,4},{4,5},{5,0}
	};

	int start = 1;

	auto result = solution(graph, start);
	for (auto r : result) {
		cout << r << " ";
	}
	return 0;
}
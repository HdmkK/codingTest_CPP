#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;


unordered_map<char, vector<char>> adjList;
vector<char> result;
unordered_set<char> visited;

void dfs(char node) {
	
	//방문
	result.push_back(node);

	for (char next : adjList[node]) {
		//방문한적이 없다면
		if (visited.find(next) == visited.end()) {
			visited.insert(next);
			dfs(next);
		}
	}
}

vector<char> solution(vector<pair<char, char>> graph, char start) {

	//인접 리스트 생성
	for (pair<char, char>& edge : graph) {
		char u = edge.first;
		char v = edge.second;
		adjList[u].push_back(v);
	}

	dfs(start);
	
	return result;
}

int main() {

	/*vector<pair<char, char>> graph{
		{'A', 'B'},
		{'B', 'C'},
		{'C', 'D'},
		{'D', 'E'}
	};*/

	vector<pair<char, char>> graph{
		{'A', 'B'},
		{'A', 'C'},
		{'B', 'D'},
		{'B', 'E'},
		{'C', 'F'},
		{'E', 'F'}
	};

	char start = 'A';

	auto result = solution(graph, start);

	for (auto r : result) {
		cout << r << " ";
	}
	return 0;
}
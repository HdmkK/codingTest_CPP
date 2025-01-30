#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> graph;
unordered_set<int> visited;

void DFS(int node) {

    visited.insert(node);

    for (int next_node : graph[node]) {
        if (visited.find(next_node) == visited.end()) {
            DFS(next_node);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    graph.resize(n);
    //인접리스트 생성
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (computers[i][j])
                graph[i].push_back(j);
        }
    }

    //방문하지 않은 노드를 발견하면 DFS탐색 시작
    for (int i = 0; i < n; ++i) {
        if (visited.find(i) == visited.end()) {
            answer += 1;
            DFS(i);
        }
    }
    return answer;
}
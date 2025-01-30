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
    //��������Ʈ ����
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (computers[i][j])
                graph[i].push_back(j);
        }
    }

    //�湮���� ���� ��带 �߰��ϸ� DFSŽ�� ����
    for (int i = 0; i < n; ++i) {
        if (visited.find(i) == visited.end()) {
            answer += 1;
            DFS(i);
        }
    }
    return answer;
}
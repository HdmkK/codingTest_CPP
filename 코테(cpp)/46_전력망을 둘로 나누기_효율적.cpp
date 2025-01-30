#include <string>
#include <vector>
#include <unordered_set>
#include <limits>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

//vector<int> adjList[101];


//깊이 우선 탐색하여 노드 개수 반환
int DFS(int cur_node, vector<vector<int>>& adjList, unordered_set<int>& visited) {

    int sum = 1;//자기 자신
    visited.insert(cur_node);

    for (int next_node : adjList[cur_node]) {
        if (visited.find(next_node) == visited.end())
            sum += DFS(next_node, adjList, visited);
    }

    return sum;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    int min_diff = numeric_limits<int>::max();
    for (int i = 0; i < wires.size(); ++i) {
        //각 반복에 대해서 현재 wire를 제외하고 인접리스트 생성

        //인접리스트 초기화
        vector<vector<int>> adjList(101);
        for (int j = 0; j < wires.size(); ++j) {

            //경로 제외
            if (i == j)
                continue;

            int x = wires[j][0];
            int y = wires[j][1];
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }


        //각 노드를 시작점으로 탐색시작(시작노드가 이미 탐색했었다면 pass)
        int group1_count = 0;
        int group2_count = 0;
        unordered_set<int> visited;

        for (int i = 1; i <= n; ++i) {
            if (visited.find(i) != visited.end())
                continue;

            //하나의 송전탑 그룹에 대해서만 DFS탐색하면, 다른 송전탑 그룹의 노드개수를 구할 수 있다.(전체 - 그룹1개수)
            group1_count = DFS(i, adjList, visited);
            group2_count = n - group1_count;

        }

        //<algorithm>에서 std::min(a, b) 함수 제공
        min_diff = min(min_diff, abs(group1_count - group2_count));
    }

    return min_diff;
}
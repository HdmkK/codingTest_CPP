/**********피드백****************/
//1. 두개의 전력망에 대해서 각각 DFS를 할 필요X
//  하나의 전력망에 대해서 DFS하여 노드 개수를 구한 후, 전체에서 해당 개수를 빼는 것이 더 효율적
//2. 최솟값 구하기
//   1) 두값에 대해서 최솟값 : #include <algorithm> ... std::min(a,b);
//   2) 컨테이너에서 최솟값 : min_element(a.begin(), b.end());



#include <string>
#include <vector>
#include <unordered_set>
#include <limits>
#include <cmath>
#include <iostream>
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
        //vector<int> adjList[101];
        vector<vector<int>> adjList(101);
        for (int j = 0; j < wires.size(); ++j) {

            //경로 제외
            if (i == j)
                continue;

            int x = wires[j][0];
            int y = wires[j][1];
            //cout << x << ", " << y << endl;
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }
        //cout << endl;


        //각 노드를 시작점으로 탐색시작(시작노드가 이미 탐색했었다면 pass)
        int group1_count = 0;
        int group2_count = 0;
        unordered_set<int> visited;

        for (int i = 1; i <= n; ++i) {
            if (visited.find(i) != visited.end())
                continue;

            if (group1_count == 0) {
                group1_count = DFS(i, adjList, visited);
            }
            else {
                group2_count = DFS(i, adjList, visited);
            }
        }

        //min_diff = min_element(array<int>{min_diff, abs(group1_count-group2_count)});
        int diff = abs(group1_count - group2_count);
        //cout << diff << endl;
        if (min_diff > diff) {
            min_diff = diff;
        }
    }

    return min_diff;
}
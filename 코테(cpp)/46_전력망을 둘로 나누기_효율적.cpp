#include <string>
#include <vector>
#include <unordered_set>
#include <limits>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

//vector<int> adjList[101];


//���� �켱 Ž���Ͽ� ��� ���� ��ȯ
int DFS(int cur_node, vector<vector<int>>& adjList, unordered_set<int>& visited) {

    int sum = 1;//�ڱ� �ڽ�
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
        //�� �ݺ��� ���ؼ� ���� wire�� �����ϰ� ��������Ʈ ����

        //��������Ʈ �ʱ�ȭ
        vector<vector<int>> adjList(101);
        for (int j = 0; j < wires.size(); ++j) {

            //��� ����
            if (i == j)
                continue;

            int x = wires[j][0];
            int y = wires[j][1];
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }


        //�� ��带 ���������� Ž������(���۳�尡 �̹� Ž���߾��ٸ� pass)
        int group1_count = 0;
        int group2_count = 0;
        unordered_set<int> visited;

        for (int i = 1; i <= n; ++i) {
            if (visited.find(i) != visited.end())
                continue;

            //�ϳ��� ����ž �׷쿡 ���ؼ��� DFSŽ���ϸ�, �ٸ� ����ž �׷��� ��尳���� ���� �� �ִ�.(��ü - �׷�1����)
            group1_count = DFS(i, adjList, visited);
            group2_count = n - group1_count;

        }

        //<algorithm>���� std::min(a, b) �Լ� ����
        min_diff = min(min_diff, abs(group1_count - group2_count));
    }

    return min_diff;
}
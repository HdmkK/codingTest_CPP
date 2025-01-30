/**********�ǵ��****************/
//1. �ΰ��� ���¸��� ���ؼ� ���� DFS�� �� �ʿ�X
//  �ϳ��� ���¸��� ���ؼ� DFS�Ͽ� ��� ������ ���� ��, ��ü���� �ش� ������ ���� ���� �� ȿ����
//2. �ּڰ� ���ϱ�
//   1) �ΰ��� ���ؼ� �ּڰ� : #include <algorithm> ... std::min(a,b);
//   2) �����̳ʿ��� �ּڰ� : min_element(a.begin(), b.end());



#include <string>
#include <vector>
#include <unordered_set>
#include <limits>
#include <cmath>
#include <iostream>
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
        //vector<int> adjList[101];
        vector<vector<int>> adjList(101);
        for (int j = 0; j < wires.size(); ++j) {

            //��� ����
            if (i == j)
                continue;

            int x = wires[j][0];
            int y = wires[j][1];
            //cout << x << ", " << y << endl;
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }
        //cout << endl;


        //�� ��带 ���������� Ž������(���۳�尡 �̹� Ž���߾��ٸ� pass)
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
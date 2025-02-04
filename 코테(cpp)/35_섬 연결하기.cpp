#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> parents(100);
vector<int> ranked(100, 0);

bool compare(const vector<int>& a, const vector<int>& b) {
    return a[2] < b[2];
}

//x가 속한 집합의 루트노드 반환
int find(int x) {

    if (parents[x] == x) return x;

    parents[x] = find(parents[x]);

    return parents[x];
}

//x와 y가 속한 집합을 합치기
void union_set(int x, int y) {
    int root_x = find(x);
    int root_y = find(y);

    if (ranked[root_x] > ranked[root_y]) {
        parents[root_y] = root_x;
    }
    else if (ranked[root_x] < ranked[root_y]) {
        parents[root_x] = root_y;
    }
    else if (ranked[root_x] == ranked[root_y]) {
        parents[root_y] = root_x;
        ranked[root_x]++;
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    //유니온-파인드를 위한 배열 초기화
    for (int i = 0; i < parents.size(); ++i) {
        parents[i] = i;
    }

    //간선 정렬
    sort(costs.begin(), costs.end(), compare);

    for (auto e : costs) {
        int u = e[0];
        int v = e[1];
        int w = e[2];

        if (find(u) == find(v)) continue;

        //하나의 집합으로 합치기->유니온
        union_set(u, v);
        answer += w;
    }
    return answer;
}
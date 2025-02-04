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

//x�� ���� ������ ��Ʈ��� ��ȯ
int find(int x) {

    if (parents[x] == x) return x;

    parents[x] = find(parents[x]);

    return parents[x];
}

//x�� y�� ���� ������ ��ġ��
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

    //���Ͽ�-���ε带 ���� �迭 �ʱ�ȭ
    for (int i = 0; i < parents.size(); ++i) {
        parents[i] = i;
    }

    //���� ����
    sort(costs.begin(), costs.end(), compare);

    for (auto e : costs) {
        int u = e[0];
        int v = e[1];
        int w = e[2];

        if (find(u) == find(v)) continue;

        //�ϳ��� �������� ��ġ��->���Ͽ�
        union_set(u, v);
        answer += w;
    }
    return answer;
}
/***********�ǵ��***************/
//1. ����� �׷����� ��, �Է����� �ܹ����ι迭�� �־�����
//   ��������Ʈ�� �� ���� ��� �߰����־���Ѵ�.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <tuple>
using namespace std;

class Compare
{
public:
    bool operator() (const tuple<int, int>& A, const tuple<int, int>& B) {
        return get<1>(A) > get<1>(B);
    }
};

void createAdjList(int N, vector<vector<int>>& road, vector<vector<tuple<int, int>>>& graph) {
    for (int i = 0; i < road.size(); ++i) {
        int src = road[i][0] - 1;
        int dst = road[i][1] - 1;
        int weight = road[i][2];
        //cout << src << " -> " << dst << ", " << weight << endl;
        graph[src].push_back({ dst, weight });
        graph[dst].push_back({ src, weight });
    }
}

unordered_map<int, int> search(int startNode, vector<vector<tuple<int, int>>>& graph, int N) {

    priority_queue<tuple<int, int>, vector<tuple<int, int>>, Compare> pq;//���ͽ�Ʈ�� ����� �켱���� ť
    unordered_map<int, int> costs;//�� ����� �ּҰŸ��� ������ ��

    pq.push({ startNode, 0 });
    costs[startNode] = 0;

    while (!pq.empty()) {

        auto [cur_node, cur_weight] = pq.top();
        pq.pop();

        //�ִܰŸ��� �������� ���� ����� �ִܰŸ� Ȯ��
        if (costs.find(cur_node) == costs.end()) {
            costs[cur_node] = cur_weight;

            //��� ��忡 ���ؼ� �ִܰŸ� Ȯ��
            if (costs.size() == N)
            {
                cout << "��" << endl;
                break;
            }

        }

        for (auto& [next_node, weight] : graph[cur_node]) {

            //�ִܰŸ��� ������ ����� pass
            if (costs.find(next_node) != costs.end())
                continue;

            pq.push({ next_node, cur_weight + weight });
        }
    }

    return costs;
}

int getVisitableNode(unordered_map<int, int>& costs, int K) {

    int sum = 0;

    for (auto it = costs.begin(); it != costs.end(); ++it) {
        pair<int, int> cur = *it;
        //cout << cur.first+1 << " -> " << cur.second << endl;
        if (cur.second <= K)
            sum++;
    }

    return sum;
}

//���Ǹ� ���� �ڵ忡�� ����ȣ-1�� ���
//���� ��ȯ�ÿ� �ٽ� +1�� ���־����.
int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;

    //��������Ʈ ����
    vector<vector<tuple<int, int>>> graph(N);
    createAdjList(N, road, graph);

    //startNode(0�� �������� �� ��忡 ���ؼ� �ִܰŸ��� ���Ѵ�.)
    int startNode = 0;
    unordered_map<int, int> costs = search(startNode, graph, N);

    answer = getVisitableNode(costs, K);
    return answer;
}
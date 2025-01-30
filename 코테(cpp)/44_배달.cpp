/***********피드백***************/
//1. 양방향 그래프일 때, 입력으로 단방향경로배열이 주어지면
//   인접리스트에 두 방향 모두 추가해주어야한다.

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

    priority_queue<tuple<int, int>, vector<tuple<int, int>>, Compare> pq;//다익스트라에 사용할 우선순위 큐
    unordered_map<int, int> costs;//각 노드의 최소거리를 저장할 맵

    pq.push({ startNode, 0 });
    costs[startNode] = 0;

    while (!pq.empty()) {

        auto [cur_node, cur_weight] = pq.top();
        pq.pop();

        //최단거리가 정해지지 않은 노드라면 최단거리 확정
        if (costs.find(cur_node) == costs.end()) {
            costs[cur_node] = cur_weight;

            //모든 노드에 대해서 최단거리 확정
            if (costs.size() == N)
            {
                cout << "끝" << endl;
                break;
            }

        }

        for (auto& [next_node, weight] : graph[cur_node]) {

            //최단거리가 정해진 노드라면 pass
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

//편의를 위해 코드에선 노드번호-1을 사용
//정답 반환시엔 다시 +1을 해주어야함.
int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;

    //인접리스트 생성
    vector<vector<tuple<int, int>>> graph(N);
    createAdjList(N, road, graph);

    //startNode(0을 기준으로 각 노드에 대해서 최단거리를 구한다.)
    int startNode = 0;
    unordered_map<int, int> costs = search(startNode, graph, N);

    answer = getVisitableNode(costs, K);
    return answer;
}
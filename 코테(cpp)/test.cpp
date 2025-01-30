//아래 코드는 테스트 코드 입니다.
#include <iterator>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Compare
{
public:
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
vector<int> solution(int start, int numNodes, const vector<tuple<int, int, int>> edges) {

    vector<int> answer;

    unordered_map<int, vector<pair<int, int>>> adjList;

    for (auto& [u, v, w] : edges) {
        adjList[u].push_back(make_pair(v, w));
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    unordered_map<int, int> costs;

    pq.push({ start, 0 });

    while (!pq.empty()) {

        pair<int, int> cur = pq.top();
        pq.pop();
        int cur_node = cur.first;
        int cur_weight = cur.second;

        if (costs.find(cur_node) == costs.end()) {
            costs[cur_node] = cur_weight;
            if (costs.size() == numNodes) break;
        }

        for (auto& [next_node, weight] : adjList[cur_node]) {
            pq.push({ next_node, cur_weight + weight });
        }
    }

    for (int i = 0; i < numNodes; ++i) {
        answer.push_back(costs[i]);
    }

    return answer;
}

void print(vector<int> vec)
{
    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;

}

int main()
{

    print(solution(0, 3, { {0, 1, 9},{0, 2, 3},{1, 0, 5},{2, 1, 1} })); //출력값 : 0 4 3
    print(solution(0, 4, { {0, 1, 1}, {1, 2, 5}, {2, 3, 1} })); //출력값 : 0 1 6 7
    return 0;
}
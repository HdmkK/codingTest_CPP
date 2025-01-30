#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <unordered_map>
using namespace std;

const int INF = numeric_limits<int>::max();

class Compare
{
public:
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return a.first > b.first;
	}
};

vector<int> solution(int start, int numNodes, vector<tuple<int, int, int >> edges) {

	vector<int> answer;

	//��������Ʈ ����
	vector < vector<pair<int, int>>> adjList(numNodes);
	for (const auto& [from, to, weight] : edges) {
		adjList[from].emplace_back(to, weight);
	}

	//���� ��带 ������ ��� ����� �ּ� ����� INF�� �ʱ�ȭ
	vector<int> distances(numNodes, INF);
	distances[start] = 0;

	//�켱���� ť�� ���۳�� �߰�
	priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
	pq.push({ 0, start });

	//�Ÿ� Ȯ���� ��
	unordered_map<int, int> costs;

	while (!pq.empty()) {

		int currentDistance = pq.top().first;
		int currentNode = pq.top().second;
		pq.pop();
		
		if (costs.find(currentNode) == costs.end())
			costs[currentNode] = currentDistance;


		//�������鿡 ���ؼ� �湮�� ����
		for (const auto& [neighbor, weight] : adjList[currentNode]) {
			
			int newDistance = currentDistance + weight;
			if (costs.find(neighbor) == costs.end())
				pq.push({ newDistance, neighbor });
		}
	}

	answer.push_back(costs[start]);

	//cost���� vector�� ��ȯ
	for (int i = 0; i < numNodes; ++i) {
		if (i == start) continue;

		answer.push_back(costs[i]);
	}
	return answer;
	
}
int main() {
	/*int start = 0;
	int numNodes = 3;
	vector<tuple<int, int, int>> edges{
		{0,1,9}, {0,2,3}, {1,0,5}, {2,1,1}
	};*/

	int start = 0;
	int numNodes = 4;
	vector<tuple<int, int, int>> edges{
		{0,1,1}, {1,2,5}, {2,3,1}
	};

	auto result = solution(start, numNodes, edges);
	for (auto v : result) {
		cout << v << " ";
	}
	return 0;
}
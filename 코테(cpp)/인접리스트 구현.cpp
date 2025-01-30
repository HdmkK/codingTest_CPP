#include <iostream>
#include <vector>

using namespace std;

struct nodeInfo {
	int V;
	int W;
};

vector<vector<nodeInfo>> adjList;


void addEdge(int u, int v, int w) {
	u -= 1;

	struct nodeInfo new_node = { v, w };
	adjList[u].push_back(new_node);
}

void printAdjList() {
	for (int i = 0; i < adjList.size(); ++i) {
		vector<nodeInfo>& adjs = adjList[i];
		for (int j = 0; j < adjs.size(); ++j) {
			cout << i + 1 << " -> " << adjs[j].V << "(W : " << adjs[j].W << ")" << endl;
		}
	}
}

int main() {

	int N = 5;

	adjList.resize(N);

	addEdge(1, 2, 3);
	addEdge(2, 1, 6);
	addEdge(2, 3, 5);
	addEdge(3, 2, 1);
	addEdge(3, 4, 13);
	addEdge(4, 4, 9);
	addEdge(4, 1, 42);

	printAdjList();
	return 0;
}
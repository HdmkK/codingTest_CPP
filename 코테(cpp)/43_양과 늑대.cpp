#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, vector<int>> adjList;
vector<bool> visited;
vector<int> nodes;
int ans = 0;

void dfs(vector<int> arr) {

    //현재 양의 개수, 늑대개수 세기
    int sheeps = 0, wolves = 0;

    for (int i : arr) {
        int type = nodes[i];
        if (type == 0) sheeps++;
        else wolves++;
    }

    if (wolves >= sheeps) return;

    ans = max(ans, sheeps);

    for (int i : arr) {
        for (int next : adjList[i]) {

            if (visited[next]) continue;

            visited[next] = true;
            arr.push_back(next);
            dfs(arr);
            arr.pop_back();
            visited[next] = false;
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    int N = info.size();

    visited.resize(N, false);
    nodes = info;
    for (auto e : edges) {
        int parent = e[0];
        int itself = e[1];
        adjList[parent].push_back(itself);
    }

    visited[0] = true;
    dfs({ 0 });

    return ans;
}
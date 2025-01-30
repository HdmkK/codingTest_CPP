#include<vector>
#include<queue>
#include<tuple>
#include<iostream>

using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    int M = maps.size();
    int N = maps[0].size();

    bool visited[100][100] = { false };//방문표시 배열

    queue<tuple<int, int, int>> q;
    q.push({ 0,0,1 });
    visited[0][0] = true;

    while (!q.empty()) {

        auto [c_x, c_y, depth] = q.front();
        q.pop();

        if (c_x == M - 1 && c_y == N - 1) {
            return depth;
        }


        for (int i = 0; i < 4; ++i) {
            int n_x = c_x + dx[i];
            int n_y = c_y + dy[i];

            if (n_x >= 0 && n_x < M && n_y >= 0 && n_y < N) {
                if (maps[n_x][n_y] == 0 || visited[n_x][n_y])
                    continue;

                q.push({ n_x, n_y, depth + 1 });
                visited[n_x][n_y] = true;
            }
        }

    }


    return answer;
}
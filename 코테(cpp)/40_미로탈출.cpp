/*********피드백***************/
//방문용 배열의 크기는 최대로 하는게 좋을 듯(크기에 상수리터럴을 넣어야하므로
//BFS는 우선순위큐말고 그냥 큐로 해도 된다.

#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <tuple>

using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

class Compare
{
public:
    bool operator() (const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
        return get<2>(a) > get<2>(b);
    }
};

int solution(vector<string> maps) {

    int M = maps.size();
    int N = maps[0].length();
    int s_x, s_y;

    int visited[100][100] = { 0 };//방문표시용 배열
    int visited2[100][100] = { 0 };//방문표시용 배열
    //그래프 초기화
    vector<vector <char>> graph(M);
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {

            graph[i].push_back(maps[i][j]);
            if (maps[i][j] == 'S') {
                s_x = i;
                s_y = j;
            }
        }
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Compare> pq;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Compare> empty;


    int to_lever = -1;

    //레버까지의 최단거리 구하기
    pq.push({ s_x, s_y, 0 });
    visited[s_x][s_y] = 1;

    while (!pq.empty()) {

        auto [c_x, c_y, depth] = pq.top();
        pq.pop();

        //레버만나면->시작좌표 갱신 및 거리 누적
        if (graph[c_x][c_y] == 'L') {
            s_x = c_x;
            s_y = c_y;
            to_lever = depth;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int n_x = c_x + dx[i];
            int n_y = c_y + dy[i];

            if (n_x >= 0 && n_x < M && n_y >= 0 && n_y < N) {
                if (graph[n_x][n_y] == 'X' || visited[n_x][n_y] == 1)
                    continue;

                pq.push({ n_x, n_y, depth + 1 });
                visited[n_x][n_y] = 1;
            }
        }
    }

    if (to_lever == -1)
        return -1;

    //이번엔 레버로부터 출구까지의 최단거리 구하기
    //레버까지의 최단거리 구하기
    pq.swap(empty);
    pq.push({ s_x, s_y, to_lever });
    visited2[s_x][s_y] = 1;

    while (!pq.empty()) {

        auto [c_x, c_y, depth] = pq.top();
        pq.pop();

        //출구만나면->시작좌표 갱신 및 거리 누적
        if (graph[c_x][c_y] == 'E') {
            return depth;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int n_x = c_x + dx[i];
            int n_y = c_y + dy[i];

            if (n_x >= 0 && n_x < M && n_y >= 0 && n_y < N) {
                if (graph[n_x][n_y] == 'X' || visited2[n_x][n_y] == 1)
                    continue;

                pq.push({ n_x, n_y, depth + 1 });
                visited2[n_x][n_y] = 1;
            }
        }
    }


    return -1;
}
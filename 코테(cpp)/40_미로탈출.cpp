/*********�ǵ��***************/
//�湮�� �迭�� ũ��� �ִ�� �ϴ°� ���� ��(ũ�⿡ ������ͷ��� �־���ϹǷ�
//BFS�� �켱����ť���� �׳� ť�� �ص� �ȴ�.

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

    int visited[100][100] = { 0 };//�湮ǥ�ÿ� �迭
    int visited2[100][100] = { 0 };//�湮ǥ�ÿ� �迭
    //�׷��� �ʱ�ȭ
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

    //���������� �ִܰŸ� ���ϱ�
    pq.push({ s_x, s_y, 0 });
    visited[s_x][s_y] = 1;

    while (!pq.empty()) {

        auto [c_x, c_y, depth] = pq.top();
        pq.pop();

        //����������->������ǥ ���� �� �Ÿ� ����
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

    //�̹��� �����κ��� �ⱸ������ �ִܰŸ� ���ϱ�
    //���������� �ִܰŸ� ���ϱ�
    pq.swap(empty);
    pq.push({ s_x, s_y, to_lever });
    visited2[s_x][s_y] = 1;

    while (!pq.empty()) {

        auto [c_x, c_y, depth] = pq.top();
        pq.pop();

        //�ⱸ������->������ǥ ���� �� �Ÿ� ����
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
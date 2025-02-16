#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
#include<cmath>
#include<algorithm>
using namespace std;

int N, M;
int s_x, s_y;
int e_x, e_y;
int g_x, g_y;
vector<tuple<int, int>> ghosts;
vector<vector<char>> board;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void input();
int getNamWooCost();
int getGhostCost(int s_x, int s_y);

bool compare(const tuple<int, int>& a, const tuple<int, int>& b) {
    int a_diff = abs(get<0>(a) - e_x) + abs(get<1>(a) - e_y);
    int b_diff = abs(get<0>(b) - e_x) + abs(get<1>(b) - e_y);
    return a_diff < b_diff;
}

int main(int argc, char** argv)
{
    input();




    //남우의 최단거리 구하기
    int NamWoo = getNamWooCost();
    if (NamWoo == 0) {
        cout << "No" << endl;
        return 0;
    }

    if (ghosts.size() == 0) {
        cout << "Yes" << endl;
        return 0;
    }

    //출구와의 거리가 가장 가까운 유령 좌표 구하기
    sort(ghosts.begin(), ghosts.end(), compare);


    auto result = ghosts[0];
    g_x = get<0>(result);
    g_y = get<1>(result);


    int ghostCost = getGhostCost(g_x, g_y);

    if (ghostCost <= NamWoo)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}

int getGhostCost(int s_x, int s_y) {

    queue<tuple<int, int, int>> q;
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    q.push({ s_x, s_y, 0 });
    visited[s_x][s_y] = true;

    while (!q.empty()) {
        auto [c_x, c_y, depth] = q.front();
        q.pop();

        if (board[c_x][c_y] == 'D') return depth;


        for (int i = 0; i < 4; ++i) {
            int n_x = c_x + dx[i];
            int n_y = c_y + dy[i];

            if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= M) continue;
            if (visited[n_x][n_y]) continue;

            q.push({ n_x, n_y, depth + 1 });
            visited[n_x][n_y] = true;
        }
    }

    return 0;
}

int getNamWooCost() {

    queue<tuple<int, int, int>> q;
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    q.push({ s_x, s_y, 0 });
    visited[s_x][s_y] = true;

    while (!q.empty()) {
        auto [c_x, c_y, depth] = q.front();
        q.pop();

        if (board[c_x][c_y] == 'D') return depth;


        for (int i = 0; i < 4; ++i) {
            int n_x = c_x + dx[i];
            int n_y = c_y + dy[i];

            if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= M) continue;
            if (board[n_x][n_y] == '#') continue;
            if (visited[n_x][n_y]) continue;

            q.push({ n_x, n_y, depth + 1 });
            visited[n_x][n_y] = true;
        }
    }

    return 0;
}

void input() {
    cin >> N >> M;
    cin.ignore();
    board.assign(N, vector<char>(M));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char c;
            cin >> c;

            if (c == 'N') {
                s_x = i;
                s_y = j;
            }
            else if (c == 'D') {
                e_x = i;
                e_y = j;
            }
            else if (c == 'G') {
                ghosts.push_back({ i, j });
            }

            board[i][j] = c;
        }
        cin.ignore();
    }
}
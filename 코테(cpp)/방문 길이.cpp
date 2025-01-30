#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <iostream>

using namespace std;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

const int N = 11;

unordered_map<char, int> dr;
bool visited[11][11][4];




void init_dr() {
    dr.insert(make_pair('U', 0));
    dr.insert(make_pair('R', 1));
    dr.insert(make_pair('D', 2));
    dr.insert(make_pair('L', 3));
}

int solution(string dirs) {
    int answer = 0;


    init_dr();

    int x = 5, y = 5;
    int n_x, n_y;
    int i = 0;
    int cnt = 0;

    for (auto cmd : dirs) {

        i = dr[cmd];
        n_x = x + dx[i];
        n_y = y + dy[i];



        //다음 방문 좌표가 범위 내일 때만
        //좌표를 이동
        //*현재 지나는 길이 이미 방문했는가 -> X면 cnt+=1q
        if ((0 <= n_x && n_x < N) && (0 <= n_y && n_y < N)) {

            if (visited[x][y][i] != 1) {
                //cout << n_x << "," << n_y << endl;
                cnt += 1;
            }


            visited[x][y][i] = 1;
            visited[n_x][n_y][(i + 2) % 4] = 1;
            x = n_x;
            y = n_y;
        }
    }


    return cnt;
}
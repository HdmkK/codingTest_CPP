#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int K, M;
vector<vector<int>> grid(5, vector<int>(5));
vector<tuple<int, int>> deleteXYyet;
vector<tuple<int, int>> deleteXY;
queue<int> q;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void input();
void printGrid(vector<vector<int>>& grid);
tuple<int, int, int, int> select();
void rotate90(int std_x, int std_y, vector<vector<int>>& cp_grid);
void rotate180(int std_x, int std_y, vector<vector<int>>& cp_grid);
void rotate270(int std_x, int std_y, vector<vector<int>>& cp_grid);
int getTresure(vector<vector<int>>& grid);
void deleteGrid();
void refillGrid();


int main() {

    input();

    for (int round = 0; round < K; ++round) {

        //cout << "=========================================" << endl;
        //cout << "================탐색시작================" << endl;
        auto [x, y, angle, value] = select();
        //cout << "===============탐색 완료================" << endl;
        if (value == 0) break;

        auto cpGrid = grid;
        if (angle == 90) rotate90(x, y, cpGrid);
        if (angle == 180) rotate180(x, y, cpGrid);
        if (angle == 270) rotate270(x, y, cpGrid);
        grid = cpGrid;


        deleteGrid();
        refillGrid();
        //cout << "=======================지우고 리필완료 =============" << endl;
        while (1) {
            int ret = getTresure(grid);
            if (ret == 0) break;

            value += ret;
            deleteXY = deleteXYyet;
            deleteGrid();
            refillGrid();
            //cout << "=======================지우고 리필완료 =============" << endl;
        }

        cout << value << " ";

        //cout << endl << endl << endl;
    }


    return 0;
}

void refillGrid() {
    for (int y = 0; y < 5; ++y) {
        for (int x = 4; x >= 0; --x) {
            if (grid[x][y] == 0) {
                grid[x][y] = q.front();
                q.pop();
            }
        }
    }
}

void deleteGrid() {
    for (auto [x, y] : deleteXY) {
        //cout << x << ", " << y << endl;

        grid[x][y] = 0;
    }
    deleteXY.clear();
}

tuple<int, int, int, int> select() {
    int max_value = 0, angle = 360, std_y = 5, std_x = 5;

    for (int x = 1; x <= 3; ++x) {
        for (int y = 1; y <= 3; ++y) {
            int value;

            // 90도
            vector<vector<int>> cp_grid90 = grid;
            rotate90(x, y, cp_grid90);
            value = getTresure(cp_grid90);
            //cout << "그리고 90도 회전일 때 유물 : " << value << endl << endl;
            if (value > max_value) {
                max_value = value;
                angle = 90;
                std_x = x;
                std_y = y;
                deleteXY = deleteXYyet;
            }
            else if (value == max_value && angle > 90) {
                max_value = value;
                angle = 90;
                std_x = x;
                std_y = y;
                deleteXY = deleteXYyet;
            }
            else if (value == max_value && angle == 90 && y < std_y) {
                max_value = value;
                angle = 90;
                std_x = x;
                std_y = y;
                deleteXY = deleteXYyet;
            }
            else if (value == max_value && angle == 90 && y == std_y && x < std_x) {
                max_value = value;
                angle = 90;
                std_x = x;
                std_y = y;
                deleteXY = deleteXYyet;
            }


            // 180도
            vector<vector<int>> cp_grid180 = grid;
            rotate180(x, y, cp_grid180);
            value = getTresure(cp_grid180);
            //cout << "그리고 180도 회전일 때 유물 : " << value << endl << endl;
            if (value > max_value) {
                max_value = value;
                angle = 180;
                std_x = x;
                std_y = y;
                deleteXY = deleteXYyet;
            }
            else if (value == max_value && angle > 180) {
                max_value = value;
                angle = 180;
                std_x = x;
                std_y = y;
                deleteXY = deleteXYyet;
            }
            else if (value == max_value && angle == 180 && y < std_y) {
                max_value = value;
                angle = 180;
                std_x = x;
                std_y = y;
                deleteXY = deleteXYyet;
            }
            else if (value == max_value && angle == 180 && y == std_y && x < std_x) {
                max_value = value;
                angle = 180;
                std_x = x;
                std_y = y;
                deleteXY = deleteXYyet;
            }


            // 270도
            vector<vector<int>> cp_grid270 = grid;
            rotate270(x, y, cp_grid270);
            value = getTresure(cp_grid270);
            //cout << "그리고 270도 회전일 때 유물 : " << value << endl << endl;
            if (value > max_value) {
                max_value = value;
                angle = 270;
                std_x = x;
                std_y = y;
                deleteXY = deleteXYyet;
            }
            else if (value == max_value && angle > 270) {
                max_value = value;
                angle = 270;
                std_x = x;
                std_y = y;
                deleteXY = deleteXYyet;
            }
            else if (value == max_value && angle == 270 && y < std_y) {
                max_value = value;
                angle = 270;
                std_x = x;
                std_y = y;
                deleteXY = deleteXYyet;
            }
            else if (value == max_value && angle == 270 && y == std_y && x < std_x) {
                max_value = value;
                angle = 270;
                std_x = x;
                std_y = y;
                deleteXY = deleteXYyet;
            }
        }
    }

    return { std_x, std_y, angle, max_value };

}




int getTresure(vector<vector<int>>& grid) {

    int totalSum = 0;
    vector<vector<bool>> visited(5, vector<bool>(5, false));
    vector<tuple<int, int>> tmpDeleteXY;
    deleteXYyet.clear();

    for (int x = 0; x < 5; ++x) {
        for (int y = 0; y < 5; ++y) {

            if (visited[x][y]) continue;


            tmpDeleteXY.clear();
            /* 탐색 */
            int s_x = x;
            int s_y = y;
            int type = grid[s_x][s_y];
            int sum = 0;

            queue<tuple<int, int, int>> q;
            q.push({ s_x, s_y, 1 });
            visited[s_x][s_y] = true;

            while (!q.empty()) {

                auto [c_x, c_y, d] = q.front();
                q.pop();

                sum++;
                tmpDeleteXY.push_back({ c_x, c_y });

                for (int i = 0; i < 4; ++i) {
                    int n_x = c_x + dx[i];
                    int n_y = c_y + dy[i];
                    if (n_x < 0 || n_x >= 5 || n_y < 0 || n_y >= 5) continue;
                    if (visited[n_x][n_y]) continue;
                    if (grid[n_x][n_y] != type) continue;

                    q.push({ n_x, n_y, d + 1 });
                    visited[n_x][n_y] = true;
                }
            }
            /* 탐색 끝 */


            if (sum < 3) continue;

            deleteXYyet.insert(deleteXYyet.end(), tmpDeleteXY.begin(), tmpDeleteXY.end());
            totalSum += sum;
        }
    }

    return totalSum;
}

void rotate90(int std_x, int std_y, vector<vector<int>>& cp_grid) {
    for (int x = std_x - 1; x <= std_x + 1; ++x) {
        for (int y = std_y - 1; y <= std_y + 1; ++y) {
            cp_grid[y - std_y + std_x][-x + std_x + std_y] = grid[x][y];
        }
    }

    //cout << "기준 좌표 : " << std_x << ", " << std_y << endl;
    //printGrid(cp_grid);
}

void rotate180(int std_x, int std_y, vector<vector<int>>& cp_grid) {
    for (int x = std_x - 1; x <= std_x + 1; ++x) {
        for (int y = std_y - 1; y <= std_y + 1; ++y) {
            cp_grid[-x + 2 * std_x][-y + 2 * std_y] = grid[x][y];
        }
    }

    //cout << "기준 좌표 : " << std_x << ", " << std_y << endl;
    //printGrid(cp_grid);
}

void rotate270(int std_x, int std_y, vector<vector<int>>& cp_grid) {
    for (int x = std_x - 1; x <= std_x + 1; ++x) {
        for (int y = std_y - 1; y <= std_y + 1; ++y) {
            cp_grid[-y + std_y + std_x][x - std_x + std_y] = grid[x][y];
        }
    }
    //cout << "기준 좌표 : " << std_x << ", " << std_y << endl;
    //printGrid(cp_grid);
}

void printGrid(vector<vector<int>>& grid) {
    for (int x = 0; x < 5; ++x) {
        for (int y = 0; y < 5; ++y) {
            cout << grid[x][y] << " ";
        }
        cout << endl;
    }
}


void input() {
    cin >> K >> M;
    for (int x = 0; x < 5; ++x) {
        for (int y = 0; y < 5; ++y) {
            cin >> grid[x][y];
        }
    }

    for (int i = 0; i < M; ++i) {
        int input;
        cin >> input;
        q.push(input);
    }
}
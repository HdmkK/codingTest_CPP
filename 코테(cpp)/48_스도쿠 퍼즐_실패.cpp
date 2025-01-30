#include <iostream>
#include <vector>
using namespace std;

bool row[9][9];
bool col[9][9];
bool square[9][9];

int getSquareIndex(int x, int y) {
    return 3 * (x / 3) + (y / 3);
}

bool check(int x, int y, int n, vector<vector<int>>& input_board) {
    //cout << "**8**" << square[2][7] << endl;
    //행 검사
    if (row[x][n - 1]) {
        //cout << "n=" << n << endl;
        //cout << "row fail" << endl;
        return false;
    }
    if (col[y][n - 1]) {
        //cout << "n=" << n << endl;
        //cout << "col fail" << endl;
        return false;
    }
    if (square[getSquareIndex(x, y)][n - 1]) {
        //cout << "n=" << n << endl;
        //cout << "square fail" << endl;
        return false;
    }
    return true;
}

void print_board(const vector<vector<int>>& input_board) {
    for (int i = 0; i < input_board.size(); ++i) {
        cout << "[";
        for (int j = 0; j < input_board[0].size(); ++j) {
            cout << input_board[i][j] << ", ";
        }
        cout << "]" << endl;
    }
}

vector<vector<int>> result;
void DFS(int start_x, int start_y, vector<vector<int>>& input_board) {

    if (start_x == 8 && start_y == 9) {
        result = input_board;
        return;
    }
    
    for (int x = start_x; x < 9; ++x) {
        for (int y = start_y; y < 9; ++y) {
            if (input_board[x][y] != 0)
                continue;

            for (int n = 1; n <= 9; ++n) {
                
                    
                    
                    
                    //이때 체크해서 통과하면 재귀호출
                    if (!check(x, y, n, input_board))
                        continue;

                    
                    input_board[x][y] = n;
                    print_board(input_board);
                    cout << "체크결과 : (" << x << ", " << y << ") " << check(x, y, n, input_board) << endl;
                    cout << "================================" << endl;
                    row[x][n - 1] = true;
                    col[y][n - 1] = true;
                    square[getSquareIndex(x, y)][n - 1] = true;
                    DFS(start_x, start_y + 1, input_board);  
                    input_board[x][y] = 0;
                    row[x][n - 1] = false;
                    col[y][n - 1] = false;
                    square[getSquareIndex(x, y)][n - 1] = false;
            }
            return;
        }
    }
}

void initCheckArray(vector<vector<int>>& input_board) {

    for (int x = 0; x < 9; ++x) {
        for (int y = 0; y < 9; ++y) {
            if (input_board[x][y] != 0) {
                row[x][input_board[x][y] - 1] = true;
                col[y][input_board[x][y] - 1] = true;
                square[getSquareIndex(x, y)][input_board[x][y] - 1] = true;

                if (square[2][7]) {
                    cout << x << ", " << y << endl;
                }
            }
        }
    }
}

vector<vector<int>> solution(vector<vector<int>> input_board) {
	vector<vector<int>> answer;

    initCheckArray(input_board);
    DFS(0, 0, input_board);
	return result;
}

int main() {

    vector<vector<int>> board{
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    auto result = solution(board);

    for (int i = 0; i < result.size(); ++i) {
        cout << "[";
        for (int j = 0; j < result[0].size(); ++j) {
            cout << result[i][j] << ", ";
        }
        cout << "]" << endl;
    }
	return 0;
}
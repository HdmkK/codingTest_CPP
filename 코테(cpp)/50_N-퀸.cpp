#include <string>
#include <vector>
#include <tuple>
#include <cmath>
using namespace std;

int answer = 0;

bool valid(int x, int y, vector<tuple<int, int>>& mem) {

    for (auto& [pre_x, pre_y] : mem) {
        //행 검사
        if (x == pre_x) return false;
        //열 검사
        if (y == pre_y) return false;
        //대각선 검사
        if (abs(x - pre_x) == abs(y - pre_y)) return false;
    }

    return true;
}


void DFS(int row, int n, vector<tuple<int, int>>& mem) {

    //마지막행까지 선택했다면 n개의 퀸을 배치한 것이므로 +1
    if (row == n) {
        answer++;
        return;
    }

    //row행의 0열부터 n-1열까지 가능한 경우의 수를 따진다.
    for (int i = 0; i < n; ++i) {

        //row행의 현재 좌표에 퀸을 놓을 수 없다면 건너뛰기
        if (!valid(row, i, mem))
            continue;

        mem.push_back({ row, i });
        DFS(row + 1, n, mem);//row+1 -> 이번 행에서 선택을 완료했으니 다음 행으로
        mem.pop_back();//백트래킹(원래상태로)
    }
}

int solution(int n) {
    //이전에 선택했던 퀸의 좌표를 저장할 배열
    vector<tuple<int, int>> mem;
    DFS(0, n, mem);
    return answer;
}
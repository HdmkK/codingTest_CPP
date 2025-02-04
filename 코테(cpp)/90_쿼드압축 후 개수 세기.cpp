#include <string>
#include <vector>
#include <iostream>
using namespace std;
int zero_num = 0;
int one_num = 0;
void dfs(vector<vector<int>>& arr, int s_x, int s_y, int length) {

    int sum = 0;
    //현재 영역에 대해서 모든 칸이 동일한 지 체크
    for (int i = s_x; i < s_x + length; ++i) {
        for (int j = s_y; j < s_y + length; ++j) {
            sum += arr[i][j];
        }
    }

    if (sum == length * length) {
        one_num++;
        return;
    }

    if (sum == 0) {
        zero_num++;
        return;
    }

    dfs(arr, s_x, s_y, length / 2);
    dfs(arr, s_x + length / 2, s_y, length / 2);
    dfs(arr, s_x, s_y + length / 2, length / 2);
    dfs(arr, s_x + length / 2, s_y + length / 2, length / 2);



}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;

    dfs(arr, 0, 0, arr.size());

    answer.push_back(zero_num);
    answer.push_back(one_num);
    return answer;
}
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {


    int M = arr1.size();
    int N = arr1[0].size();
    int L = arr2[0].size();

    vector<vector<int>> answer(M, vector<int>(L, 0));

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < L; ++j) {
            int sum = 0;
            for (int k = 0; k < N; ++k) {
                sum += arr1[i][k] * arr2[k][j];
            }
            answer[i][j] = sum;
        }
    }
    return answer;
}
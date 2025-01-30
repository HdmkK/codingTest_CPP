#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> matrix1, 
    vector<vector<int>> matrix2) {

    
    //M = 행렬1의 행
    //L = 행렬2의 열
    //temp = M X L
    int M = matrix1.size();
    int L = matrix2[0].size();
    vector<vector<int>> temp(M, vector<int>(L));
    //곱하기
    for (int i = 0; i < matrix1.size(); ++i) {
        for (int j = 0; j < matrix2[0].size(); ++j) {
            int sum = 0;
            for (int k = 0; k < matrix2.size(); ++k) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            temp[i][j] = sum;
        }
    }
    vector<vector<int>> answer(L, vector<int>(M));
    //전치
    for (int i = 0; i < temp.size(); ++i) {
        for (int j = 0; j < temp[0].size(); ++j) {
            answer[j][i] = temp[i][j];
        }
    }
    return answer;
}

void print(vector<vector<int>> vec)
{
    for (int i = 0; i < vec.size(); i++) {
        copy(vec[i].begin(), vec[i].end(), std::ostream_iterator<int>(cout, " "));
        cout << endl;
    }

}

int main() {

 

    print(solution({
                     {2, 4 ,6},
                     {1, 3, 5},
                     {7, 8, 9},
        },
                    {
                     {9, 1, 2},
                     {4, 5, 6},
                     {7, 3, 8},
                    }
     ));
	return 0;
}
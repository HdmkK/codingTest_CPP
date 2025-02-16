#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
vector<double> F;
vector<vector<int>> board(4, vector<int>(4));
double sum = 0;

void input();
void combination(vector<int>& arr);
bool compare(const tuple<int, int>& a, const tuple<int, int>& b);

int main(int argc, char** argv)
{
    input();

    vector<int> arr;
    combination(arr);

    cout << fixed << setprecision(3) << round(sum * 1000) / 1000 << endl;
    return 0;
}

//반환값 -1 : 현재 조합은 1번 루돌프가 2순위안에 못듬.
void start(vector<int>& arr) {

    for (int i = 0; i < arr.size(); ++i) {
        if (i >= 0 && i <= 2)
            board[0][i + 1] = arr[i];
        else if (i >= 3 && i <= 4)
            board[1][i - 1] = arr[i];
        else
            board[2][i - 2] = arr[i];
    }



    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (i <= j) continue;

            //2 : 이김 1 : 비김 0 : 짐
            board[i][j] = 2 - board[j][i];
        }
    }



    vector<tuple<int, int>> rate;

    for (int i = 0; i < 4; ++i) {
        int sum = 0;
        for (int j = 0; j < 4; ++j) {
            if (i == j) continue;

            if (board[i][j] == 2) sum += 3;
            if (board[i][j] == 1) sum += 1;
        }
        rate.push_back({ i + 1, sum });
    }

    sort(rate.begin(), rate.end(), compare);

    //1번 루돌프가 2등안에 못들었음으로 현재 경우의 수는 폐기
    if (get<0>(rate[0]) != 1 && get<0>(rate[1]) != 1) {
        //cout << "No" << endl;
        return;
    }

    //확률을 구해서 누적한다.
    double subSum = 1;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {

            if (i >= j) continue;

            if (board[i][j] == 2) {//i가 j에게 이김
                subSum *= 4.0 * F[i] / (5.0 * F[i] + 5.0 * F[j]);
            }
            else if (board[i][j] == 1) {//비김
                subSum *= (F[i] + F[j]) / (5.0 * F[i] + 5.0 * F[j]);
            }
            else if (board[i][j] == 0) {//i가 j에게 짐
                subSum *= 4 * F[j] / (5 * F[i] + 5 * F[j]);
            }
        }

    }
    subSum *= 100;
    sum += subSum;

}

//0: n번째 1: 점수합
bool compare(const tuple<int, int>& a, const tuple<int, int>& b) {
    if (get<1>(a) == get<1>(b))
        return get<0>(a) < get<0>(b);
    return get<1>(a) > get<1>(b);
}

void combination(vector<int>& arr) {

    if (arr.size() == 6) {
        //조합을 구했으니 계산 시작
        start(arr);
        return;
    }

    for (int i = 0; i < 3; ++i) {
        arr.push_back(i);
        combination(arr);
        arr.pop_back();
    }
}

void input() {
    for (int i = 0; i < 4; ++i) {
        double input;
        cin >> input;
        F.push_back(input);
    }
}
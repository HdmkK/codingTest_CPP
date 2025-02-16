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

//��ȯ�� -1 : ���� ������ 1�� �絹���� 2�����ȿ� ����.
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

            //2 : �̱� 1 : ��� 0 : ��
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

    //1�� �絹���� 2��ȿ� ����������� ���� ����� ���� ���
    if (get<0>(rate[0]) != 1 && get<0>(rate[1]) != 1) {
        //cout << "No" << endl;
        return;
    }

    //Ȯ���� ���ؼ� �����Ѵ�.
    double subSum = 1;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {

            if (i >= j) continue;

            if (board[i][j] == 2) {//i�� j���� �̱�
                subSum *= 4.0 * F[i] / (5.0 * F[i] + 5.0 * F[j]);
            }
            else if (board[i][j] == 1) {//���
                subSum *= (F[i] + F[j]) / (5.0 * F[i] + 5.0 * F[j]);
            }
            else if (board[i][j] == 0) {//i�� j���� ��
                subSum *= 4 * F[j] / (5 * F[i] + 5 * F[j]);
            }
        }

    }
    subSum *= 100;
    sum += subSum;

}

//0: n��° 1: ������
bool compare(const tuple<int, int>& a, const tuple<int, int>& b) {
    if (get<1>(a) == get<1>(b))
        return get<0>(a) < get<0>(b);
    return get<1>(a) > get<1>(b);
}

void combination(vector<int>& arr) {

    if (arr.size() == 6) {
        //������ �������� ��� ����
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
#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    n = floor(log(n) / log(2));
    a = pow(2, n) - 2 + a;
    b = pow(2, n) - 2 + b;

    cout << a << ", " << b << endl;
    //a�� b�� ������ ������
    while (a != b) {

        cout << a << ", " << b << endl;
        //a ó��
        if (a % 2 == 0) {//¦��
            a = (a - 2) / 2;
        }
        else {
            a = (a - 1) / 2;
        }

        //b ó��
        if (b % 2 == 0) {//¦��
            b = (b - 2) / 2;
        }
        else {
            b = (b - 1) / 2;
        }
    }

    //cout << a << endl;

    answer = n - floor(log(a + 1) / log(2));
    return answer;
}
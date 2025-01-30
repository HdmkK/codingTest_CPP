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
    //a와 b가 같아질 때까지
    while (a != b) {

        cout << a << ", " << b << endl;
        //a 처리
        if (a % 2 == 0) {//짝수
            a = (a - 2) / 2;
        }
        else {
            a = (a - 1) / 2;
        }

        //b 처리
        if (b % 2 == 0) {//짝수
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
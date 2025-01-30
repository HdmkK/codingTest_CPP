/**************피드백************************/
// x값이 주어졌을 때, y = n / x(y는 자연수)를 만족하는지 확인하려면
// 그냥 yellw가 x로 나누어떨어지는지(나머지가 0)인지 확인하면 된다.


#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int x, y;

    //검사할 x의 범위를 충분히 준다.
    for (x = 1; x <= 5000; ++x) {

        //y가 자연수인지 확인하여 방정식이 성립하는지 확인
        /*double d_y = yellow / static_cast<double>(x);
        if (d_y != floor(d_y))*/
        if (yellow % x > 0)
            continue;
        y = yellow / x;

        //y가 정해졌다면 x에 대해서도 방정식이 성립하는지 확인
        if (x + y != (brown - 4) / 2)
            continue;

        //통과 -> x, y 확정
        break;
    }

    //x+2, y+2 중 더 긴것이 가로길이
    if (x + 2 >= y + 2) {
        answer.push_back(x + 2);
        answer.push_back(y + 2);
    }
    else {
        answer.push_back(y + 2);
        answer.push_back(x + 2);
    }
    return answer;
}
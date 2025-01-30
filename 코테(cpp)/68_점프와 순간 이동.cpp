#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;

    //도착지부터 출발지(0)으로 거꾸로 생각해본다.
    while (n > 0) {
        if (n % 2 == 0) {//짝수면 이전위치에서 X 2하여 비용이 없기 때문에 -> 반대로 / 2만 하면 된다.
            n /= 2;
        }
        else {//홀수면 이전위치가 짝수인 상태에서 + 1칸을 이동(가장 효츌적) -> -1을 하고 비용 + 1
            n -= 1;
            ans++;
        }
    }

    return ans;
}
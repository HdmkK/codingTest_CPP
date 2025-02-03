#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int cursor = 1;

    for (int station : stations) {

        while (cursor <= station + w) {
            if (cursor >= station - w) {
                cursor = station + w + 1;
                break;
            }
            answer += 1;
            cursor += 2 * w + 1;
        }
    }

    while (cursor <= n) {
        answer += 1;
        cursor += 2 * w + 1;
    }

    return answer;
}
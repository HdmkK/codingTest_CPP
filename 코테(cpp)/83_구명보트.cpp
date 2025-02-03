#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    deque<int> dq(people.begin(), people.end());
    sort(dq.begin(), dq.end());

    while (!dq.empty()) {

        if (dq.size() == 1) {
            answer += 1;
            break;
        }

        int f = dq.front();
        int b = dq.back();

        if (f + b <= limit) {
            answer += 1;
            dq.pop_front();
            dq.pop_back();
        }
        else {
            answer += 1;
            dq.pop_back();
        }
    }
    return answer;
}
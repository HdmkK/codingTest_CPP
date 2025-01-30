#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    unordered_map<string, int> want_map;
    unordered_map<string, int> cur_state;

    //정현이가 원하는 제품 map생성
    for (int i = 0; i < want.size(); ++i) {
        want_map[want[i]] = number[i];
    }

    //첫째날에 회원가입할 때 할인 구매할 수 있는 제품 맵을 초기화
    for (int i = 0; i < 10; ++i) {
        cur_state[discount[i]]++;
    }

    //회원가입 날짜를 하루씩 옮기면서 두 맵을 비교한다.
    for (int i = 0; i < discount.size() - 9; ++i) {
        if (want_map == cur_state) {
            answer++;
        }

        //에러 방지용
        if (i == discount.size() - 10) break;

        if (--cur_state[discount[i]] == 0)
            cur_state.erase(discount[i]);
        cur_state[discount[i + 10]]++;
    }
    return answer;
}
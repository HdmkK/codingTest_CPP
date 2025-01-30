#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    unordered_map<string, int> want_map;
    unordered_map<string, int> cur_state;

    //�����̰� ���ϴ� ��ǰ map����
    for (int i = 0; i < want.size(); ++i) {
        want_map[want[i]] = number[i];
    }

    //ù°���� ȸ�������� �� ���� ������ �� �ִ� ��ǰ ���� �ʱ�ȭ
    for (int i = 0; i < 10; ++i) {
        cur_state[discount[i]]++;
    }

    //ȸ������ ��¥�� �Ϸ羿 �ű�鼭 �� ���� ���Ѵ�.
    for (int i = 0; i < discount.size() - 9; ++i) {
        if (want_map == cur_state) {
            answer++;
        }

        //���� ������
        if (i == discount.size() - 10) break;

        if (--cur_state[discount[i]] == 0)
            cur_state.erase(discount[i]);
        cur_state[discount[i + 10]]++;
    }
    return answer;
}
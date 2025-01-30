#include <string>
#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

class FailRate {
public:
    int which_stage;
    double fail_rate;
public:
    FailRate(int stage) : which_stage(stage), fail_rate(0) {};
};

bool compare(const FailRate& a, const FailRate& b) {
    if (a.fail_rate == b.fail_rate)
        return a.which_stage < b.which_stage;
    return a.fail_rate > b.fail_rate;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> challenges(N, 0);
    vector<FailRate> failRate;

    //�������� �������� ���� �ʱ�ȭ
    for (int i = 0; i < N; ++i) {
        failRate.push_back(FailRate(i + 1));
    }

    //���������� �������� �ο� ���ϱ�
    for (int i = 0; i < stages.size(); ++i) {
        if (stages[i] - 1 >= N) continue;
        challenges[stages[i] - 1]++;
    }

    int rest = stages.size();

    for (int i = 0; i < N; ++i) {

        //���� �������� ���ķ� ������ ��� 0
        if (rest == 0)
            break;

        failRate[i].fail_rate = static_cast<double>(challenges[i]) / rest;
        rest -= challenges[i];
    }

    sort(failRate.begin(), failRate.end(), compare);

    for (int i = 0; i < failRate.size(); ++i) {
        answer.push_back(failRate[i].which_stage);
    }
    return answer;
}
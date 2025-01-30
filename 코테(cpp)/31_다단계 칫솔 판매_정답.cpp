#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;

    //각 멤버에 대해서 결과를 저장할 맵
    unordered_map<string, int> mem;
    for (string name : enroll) {
        mem[name] = 0;
    }

    //각 멤버의 부모를 저장할 맵
    unordered_map<string, string> parent;
    for (int i = 0; i < enroll.size(); ++i) {
        parent.insert(make_pair(enroll[i], referral[i]));
    }
    //각 판매에 대해서 자신과 그 위 부모 노드들의 이익을 누적
    for (int i = 0; i < seller.size(); ++i) {

        //셀러 자신의 이익 누적
        string name = seller[i];
        int selling_price = amount[i] * 100;

        string cur_parent = parent[name];
        string cur_name = name;
        int incentive = selling_price / 10;

        mem[cur_name] += (selling_price - incentive);

        cur_name = cur_parent;
        cur_parent = parent[cur_name];

        //그위 부모 노드들의 이익을 누적
        while (cur_name != "-") {
            mem[cur_name] += incentive - (incentive / 10);
            incentive /= 10;

            if (incentive == 0) break;

            cur_name = cur_parent;
            cur_parent = parent[cur_name];
        }
    }

    for (string name : enroll) {
        answer.push_back(mem[name]);
    }

    return answer;
}
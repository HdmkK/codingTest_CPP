#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> mem;

    //해시 테이블 만들기
    for (auto it = completion.begin(); it != completion.end(); ++it) {

        /*if (mem.find(*it) == mem.end()) {
            mem.insert(make_pair(*it, 1));
            continue;
        }

        mem[*it] += 1;*/

        mem[*it]++;
    }

    //참가자들이 완주자목록(해시테이블)에 있는지 체크
    for (auto it = participant.begin(); it != participant.end(); ++it) {
        if (mem.find(*it) != mem.end()) {
            if (mem[*it] > 0) mem[*it]--; //동명이인이 있을 수도 있으므로
            if (mem[*it] == 0) mem.erase(*it);
            continue;
        }

        return *it;
    }

}
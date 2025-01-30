#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map<string, unordered_set<string>> reporting;//각 유저별 어떤 유저를 신고했는지
    unordered_map<string, unordered_set<string>> reported;//각 유저별 어떤 유저로부터 신고당했는지
    unordered_set<string> banId;//정지 처리될 유저

    //누가 누굴 신고했는지 초기화
    for (string log : report) {
        string A, B;
        stringstream ss(log);
        ss >> A >> B;
        reporting[A].insert(B);
        reported[B].insert(A);
    }

    //k번 이상 신고된 유저를 정지처리
    for (auto it = reported.begin(); it != reported.end(); ++it) {
        string id = it->first;
        if (it->second.size() >= k)
            banId.insert(id);
    }

    //각 유저에 대해서, 해당 유저가 신고한 id중 몇개가 정지처리됐는지 구함
    for (string id : id_list) {
        int sum = 0;
        for (string bannedId : banId) {
            if (reporting[id].find(bannedId) != reporting[id].end())
                sum++;
        }
        answer.push_back(sum);
    }
    return answer;
}
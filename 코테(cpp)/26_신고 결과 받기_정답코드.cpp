#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map<string, unordered_set<string>> reported_user;
    unordered_map<string, int> count;

    //신고당한id - {신고한 id1, 신고한 id2....}
    for (const string& r : report) {
        string A, B;
        stringstream ss(r);
        ss >> A >> B;
        reported_user[B].insert(A);
    }

    //k번 이상 신고당한 id에 대해서, 신고주체들을 ++
    for (const auto& [reported_id, reporting_id_lst] : reported_user) {
        if (reporting_id_lst.size() < k) continue;

        for (const string id : reporting_id_lst) {
            count[id]++;
        }
    }

    //벡터로 변환(유저id 순으로)
    for (string id : id_list) {
        answer.push_back(count[id]);
    }
    return answer;
}
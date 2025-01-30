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

    //�Ű����id - {�Ű��� id1, �Ű��� id2....}
    for (const string& r : report) {
        string A, B;
        stringstream ss(r);
        ss >> A >> B;
        reported_user[B].insert(A);
    }

    //k�� �̻� �Ű���� id�� ���ؼ�, �Ű���ü���� ++
    for (const auto& [reported_id, reporting_id_lst] : reported_user) {
        if (reporting_id_lst.size() < k) continue;

        for (const string id : reporting_id_lst) {
            count[id]++;
        }
    }

    //���ͷ� ��ȯ(����id ������)
    for (string id : id_list) {
        answer.push_back(count[id]);
    }
    return answer;
}
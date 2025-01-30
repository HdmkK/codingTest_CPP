#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map<string, unordered_set<string>> reporting;//�� ������ � ������ �Ű��ߴ���
    unordered_map<string, unordered_set<string>> reported;//�� ������ � �����κ��� �Ű���ߴ���
    unordered_set<string> banId;//���� ó���� ����

    //���� ���� �Ű��ߴ��� �ʱ�ȭ
    for (string log : report) {
        string A, B;
        stringstream ss(log);
        ss >> A >> B;
        reporting[A].insert(B);
        reported[B].insert(A);
    }

    //k�� �̻� �Ű�� ������ ����ó��
    for (auto it = reported.begin(); it != reported.end(); ++it) {
        string id = it->first;
        if (it->second.size() >= k)
            banId.insert(id);
    }

    //�� ������ ���ؼ�, �ش� ������ �Ű��� id�� ��� ����ó���ƴ��� ����
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
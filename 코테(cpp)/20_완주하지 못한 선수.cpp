#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> mem;

    //�ؽ� ���̺� �����
    for (auto it = completion.begin(); it != completion.end(); ++it) {

        /*if (mem.find(*it) == mem.end()) {
            mem.insert(make_pair(*it, 1));
            continue;
        }

        mem[*it] += 1;*/

        mem[*it]++;
    }

    //�����ڵ��� �����ڸ��(�ؽ����̺�)�� �ִ��� üũ
    for (auto it = participant.begin(); it != participant.end(); ++it) {
        if (mem.find(*it) != mem.end()) {
            if (mem[*it] > 0) mem[*it]--; //���������� ���� ���� �����Ƿ�
            if (mem[*it] == 0) mem.erase(*it);
            continue;
        }

        return *it;
    }

}
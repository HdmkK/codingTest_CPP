#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_set<string> mem;

    //�ؽ����̺� ����
    for (string& word : phone_book) {
        mem.insert(word);
    }

    for (string& word : phone_book) {
        //word.length()-1�ϴ� ������ �ؽ����̺��� �ڱ��ڽ��� �˻����� �����ϱ� ����
        for (int offset = 1; offset <= word.length() - 1; ++offset) {
            if (mem.find(word.substr(0, offset)) != mem.end())
                return false;
        }
    }

    return true;
}
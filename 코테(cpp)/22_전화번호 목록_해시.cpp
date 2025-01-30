#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_set<string> mem;

    //해시테이블 생성
    for (string& word : phone_book) {
        mem.insert(word);
    }

    for (string& word : phone_book) {
        //word.length()-1하는 이유는 해시테이블에서 자기자신은 검색에서 제외하기 위함
        for (int offset = 1; offset <= word.length() - 1; ++offset) {
            if (mem.find(word.substr(0, offset)) != mem.end())
                return false;
        }
    }

    return true;
}
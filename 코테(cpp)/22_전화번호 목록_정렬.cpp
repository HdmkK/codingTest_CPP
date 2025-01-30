#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    int N = phone_book.size();
    if (N == 1)
        return false;

    //사전 순으로 정렬(접두어 관계가 있다면 인접하게 정렬된다.)
    sort(phone_book.begin(), phone_book.end());

    for (int i = 1; i < phone_book.size(); ++i) {
        //이전번호 phone_book[i-1]
        //현재번호 phone_book[i]
        if (phone_book[i - 1] == phone_book[i].substr(0, phone_book[i - 1].length()))
            return false;

    }

    return answer;
}
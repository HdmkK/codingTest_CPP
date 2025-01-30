#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    int N = phone_book.size();
    if (N == 1)
        return false;

    //���� ������ ����(���ξ� ���谡 �ִٸ� �����ϰ� ���ĵȴ�.)
    sort(phone_book.begin(), phone_book.end());

    for (int i = 1; i < phone_book.size(); ++i) {
        //������ȣ phone_book[i-1]
        //�����ȣ phone_book[i]
        if (phone_book[i - 1] == phone_book[i].substr(0, phone_book[i - 1].length()))
            return false;

    }

    return answer;
}
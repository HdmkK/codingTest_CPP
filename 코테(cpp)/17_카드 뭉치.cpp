#include <string>
#include <vector>
#include <queue>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    queue<string> q_cards1;
    queue<string> q_cards2;

    //cards1, cards2를 큐로 만들기
    for (string& card : cards1) {
        q_cards1.push(card);
    }

    for (string& card : cards2) {
        q_cards2.push(card);
    }

    for (string word : goal) {

        if (!q_cards1.empty() && word == q_cards1.front()) {
            q_cards1.pop();
            continue;
        }

        if (!q_cards2.empty() && word == q_cards2.front()) {
            q_cards2.pop();
            continue;
        }

        return "No";
    }

    return "Yes";
}
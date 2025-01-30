#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_set<string> mem;

    int N = words.size();
    int round = 0; // 현재 몇번째 라운드?
    int cur_turn; // 어떤 사람의 차례?
    char prev_char = words[0][0]; //이전 사람이 말한 단어의 마지막 글자

    for (int i = 0; i < N; ++i) {

        string& cur_word = words[i];

        //라운드 및 차례 정보 갱신
        cur_turn = i % n;
        if (cur_turn == 0)
            round++;

        //끝말잇기 실패 or 이미 말한 단어 -> 탈락한 사람 및 현재 라운드를 반환
        if (prev_char != cur_word[0] || mem.find(cur_word) != mem.end()) {
            return vector<int>{cur_turn + 1, round};
        }

        //해시테이블(이미 말한 단어)에 갱신
        mem.insert(cur_word);

        //다음 사람의 끝말잇기 성공 체크를 위해 prev_char갱신
        prev_char = cur_word[cur_word.length() - 1];

    }

    //모두 끝말잇기 성공
    return vector<int>{0, 0};
}
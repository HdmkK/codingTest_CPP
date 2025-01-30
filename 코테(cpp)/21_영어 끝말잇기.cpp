#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_set<string> mem;

    int N = words.size();
    int round = 0; // ���� ���° ����?
    int cur_turn; // � ����� ����?
    char prev_char = words[0][0]; //���� ����� ���� �ܾ��� ������ ����

    for (int i = 0; i < N; ++i) {

        string& cur_word = words[i];

        //���� �� ���� ���� ����
        cur_turn = i % n;
        if (cur_turn == 0)
            round++;

        //�����ձ� ���� or �̹� ���� �ܾ� -> Ż���� ��� �� ���� ���带 ��ȯ
        if (prev_char != cur_word[0] || mem.find(cur_word) != mem.end()) {
            return vector<int>{cur_turn + 1, round};
        }

        //�ؽ����̺�(�̹� ���� �ܾ�)�� ����
        mem.insert(cur_word);

        //���� ����� �����ձ� ���� üũ�� ���� prev_char����
        prev_char = cur_word[cur_word.length() - 1];

    }

    //��� �����ձ� ����
    return vector<int>{0, 0};
}
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, string> parent;
unordered_map<string, int> mem;
void dfs(string name, int incentive) {
    if (name == "-") return;//������ �ö�
    if (incentive == 0) return;//���̻� �Ž��� �ö� �ʿ�X(�����ε� incentive�� 0�� ���̹Ƿ�)
    mem[name] += incentive - (incentive / 10);//���� ����� ���ؼ� ���� ����
    string parent_name = parent[name];//�θ� ����

    dfs(parent_name, incentive / 10);//�θ� ���ؼ� ó��
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;

    //�θ� ������ ��, �� ����� ������ ������ ���� �ʱ�ȭ
    for (int i = 0; i < enroll.size(); ++i) {
        parent.insert(make_pair(enroll[i], referral[i]));
        mem.insert(make_pair(enroll[i], 0));
    }
    
    //�� �Ǹű�Ͽ� ���ؼ� -> ��ͷ� �Ž��� �ö󰡸鼭 ������ ����
    for (int i = 0; i < seller.size(); ++i) {
        dfs(seller[i], amount[i] * 100);
    }

    //���͵��� �迭�� ���ʴ�� ����
    for (int i = 0; i < enroll.size(); ++i) {
        answer.push_back(mem[enroll[i]]);
    }
    return answer;
}
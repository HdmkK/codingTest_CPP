#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cmath>
using namespace std;

int max_value = 0;
//�� ���ȣ�⸶��, ���� ������ ���� ������ ������ �ϳ��� ����.
//��� ������ �湮 or �Ƿε� ������ ���ϸ� ��Ʈ��ŷ
void DFS(vector<vector<int>>& dungeons, unordered_set<int>& mem, int fatigue, int N) {

    //���� ��� ������ Ž���ߴٸ� �ִ� ����
    if (mem.size() == N) {
        max_value = max(max_value, static_cast<int>(mem.size()));
        return;
    }

    for (int i = 0; i < dungeons.size(); ++i) {
        if (mem.find(i) == mem.end()) {
            if (fatigue >= dungeons[i][0]) {
                //���� �湮���߰� �湮�ϱ⿡ �Ƿε��� ����ϴٸ� �湮
                mem.insert(i);
                DFS(dungeons, mem, fatigue - dungeons[i][1], N);
                mem.erase(i);//���� ����� ���� ���� �������·� ����
            }
            else {//���� ������ Ž������ �ʾ����� �Ƿε��� �����Ͽ� ���̻� ������ �� ���� ��
                //���̻� �����Ƿ� �ִ밪�� ����(insert�� ���ϹǷ� ��Ʈ��ŷ�Ѱų� ��������)
                max_value = max(max_value, static_cast<int>(mem.size()));
            }
        }
    }

}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    unordered_set<int> mem;
    DFS(dungeons, mem, k, dungeons.size());
    return max_value;
}
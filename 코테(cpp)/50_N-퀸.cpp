#include <string>
#include <vector>
#include <tuple>
#include <cmath>
using namespace std;

int answer = 0;

bool valid(int x, int y, vector<tuple<int, int>>& mem) {

    for (auto& [pre_x, pre_y] : mem) {
        //�� �˻�
        if (x == pre_x) return false;
        //�� �˻�
        if (y == pre_y) return false;
        //�밢�� �˻�
        if (abs(x - pre_x) == abs(y - pre_y)) return false;
    }

    return true;
}


void DFS(int row, int n, vector<tuple<int, int>>& mem) {

    //����������� �����ߴٸ� n���� ���� ��ġ�� ���̹Ƿ� +1
    if (row == n) {
        answer++;
        return;
    }

    //row���� 0������ n-1������ ������ ����� ���� ������.
    for (int i = 0; i < n; ++i) {

        //row���� ���� ��ǥ�� ���� ���� �� ���ٸ� �ǳʶٱ�
        if (!valid(row, i, mem))
            continue;

        mem.push_back({ row, i });
        DFS(row + 1, n, mem);//row+1 -> �̹� �࿡�� ������ �Ϸ������� ���� ������
        mem.pop_back();//��Ʈ��ŷ(�������·�)
    }
}

int solution(int n) {
    //������ �����ߴ� ���� ��ǥ�� ������ �迭
    vector<tuple<int, int>> mem;
    DFS(0, n, mem);
    return answer;
}
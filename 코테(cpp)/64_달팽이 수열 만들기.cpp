//�Ʒ� �ڵ�� �׽�Ʈ �ڵ� �Դϴ�.
#include <iterator>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> solution(int n) {

    vector<vector<int>> answer(n, vector<int>(n, 0));

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    
    int N = n * n;
    int cnt = 1;

    //���� ����
    int dx[] = { 0, 1, 0, -1 };
    int dy[] = { 1, 0, -1, 0 };
    int i = 0;
    int x = 0, y = 0;


    while (cnt <= N) {
        answer[x][y] = cnt;
        visited[x][y] = true;

        //���� ĭ ��ȿ���� üũ
        int n_x = x + dx[i];
        int n_y = y + dy[i];

        if (0 > n_x || n_x >= n || 0 > n_y || n_y >= n || visited[n_x][n_y]) {
                i = (i + 1) % 4;  
        }

        x += dx[i];
        y += dy[i];
        cnt++;
        
    }

    return answer;
}

void print(vector<vector<int>> vec)
{
    for (int i = 0; i < vec.size(); i++) {
        copy(vec[i].begin(), vec[i].end(), std::ostream_iterator<int>(cout, " "));
        cout << endl;
    }

}

int main()
{
    //print(solution(3));
    /*
    ��°� :
    1 2 3
    8 9 4
    7 6 5
    */

    print(solution(4));
    /*
    ��°�:
    1 2 3 4
    12 13 14 5
    11 16 15 6
    10 9 8 7
    */
    return 0;
}
/**************�ǵ��************************/
// x���� �־����� ��, y = n / x(y�� �ڿ���)�� �����ϴ��� Ȯ���Ϸ���
// �׳� yellw�� x�� �������������(�������� 0)���� Ȯ���ϸ� �ȴ�.


#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int x, y;

    //�˻��� x�� ������ ����� �ش�.
    for (x = 1; x <= 5000; ++x) {

        //y�� �ڿ������� Ȯ���Ͽ� �������� �����ϴ��� Ȯ��
        /*double d_y = yellow / static_cast<double>(x);
        if (d_y != floor(d_y))*/
        if (yellow % x > 0)
            continue;
        y = yellow / x;

        //y�� �������ٸ� x�� ���ؼ��� �������� �����ϴ��� Ȯ��
        if (x + y != (brown - 4) / 2)
            continue;

        //��� -> x, y Ȯ��
        break;
    }

    //x+2, y+2 �� �� ����� ���α���
    if (x + 2 >= y + 2) {
        answer.push_back(x + 2);
        answer.push_back(y + 2);
    }
    else {
        answer.push_back(y + 2);
        answer.push_back(x + 2);
    }
    return answer;
}
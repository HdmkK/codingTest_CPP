#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;

    //������ ���� ���� ����, ���κ� ������ ������ �� ����
    //(ó���� ������ ������ũ ��ü�� �Դ´ٰ� ����)
    int cases_b = 0;
    unordered_map<int, int> mem_b;
    for (int i = 0; i < topping.size(); ++i) {
        int value = topping[i];

        if (mem_b.find(value) == mem_b.end())
            cases_b++;

        mem_b[value]++;
    }


    //ö���� �Ȱ��� ���� ����, ���� �� ������ ������ �� ����
    //���� ���� ������ �������� ���� �������� ����
    //->������ ���� == ���� ���� => answer(�����)++
    int cases_a = 0;
    unordered_map<int, int> mem_a;
    for (int i = 0; i < topping.size(); ++i) {
        int value = topping[i];

        //ö���� ����
        if (mem_a.find(value) == mem_a.end())
            cases_a++;
        mem_a[value]++;

        //������ ����
        if (--mem_b[value] == 0) {
            cases_b--;
            mem_b.erase(value);
        }

        if (cases_a == cases_b) answer++;

    }
    return answer;
}
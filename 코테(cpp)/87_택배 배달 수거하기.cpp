#include <string>
#include <vector>
#include <iostream>
using namespace std;

void update(vector<int>& arr, int& pos, int cap);
void print_arr(vector<int>& arr);
void print_info(int pos);

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;

    int delivery_pos = deliveries.size() - 1;
    int pickup_pos = pickups.size() - 1;

    while (delivery_pos >= 0 || pickup_pos >= 0) {

        //���� 0���� ū �� �� ���� �������� �ε����� ����
        while (delivery_pos >= 0 && deliveries[delivery_pos] == 0)
            delivery_pos--;
        while (pickup_pos >= 0 && pickups[pickup_pos] == 0)
            pickup_pos--;

        //delivery_pos, pickup_pos�� �� ū ��*2�� ����
        //(��¥�� �������� �����ϱ� ������ �� �հ��� �������� �պ�
        answer += max(delivery_pos + 1, pickup_pos + 1) * 2;

        //cap�� �������� ��� �迭, ���� �迭�� ���� ����
        //(����� ���� ����(���� ��)�� Ʈ���� ���ڰ� ���Բ��� �ϸ�ǹǷ�
        // ��޿��� �ִ� cap�� �E �� ���� ��ŭ ����
        // ���������� �ִ� cap�� �� �� ���� ��ŭ ����.)
        update(deliveries, delivery_pos, cap);
        update(pickups, pickup_pos, cap);

    }
    return answer;
}

void print_info(int pos) {
    cout << "pos : " << pos << endl;
}

void print_arr(vector<int>& arr) {
    for (int e : arr) {
        cout << e << " ";
    }
    cout << endl;
}

void update(vector<int>& arr, int& pos, int cap) {
    while (pos >= 0 && cap > 0) {
        if (cap > arr[pos]) {
            cap -= arr[pos];
            arr[pos] = 0;
            pos--;
        }
        else if (cap < arr[pos]) {
            arr[pos] -= cap;
            cap = 0;
            break;
        }
        else if (cap == arr[pos]) {
            cap = 0;
            arr[pos] = 0;
            pos--;
            break;
        }
    }
}
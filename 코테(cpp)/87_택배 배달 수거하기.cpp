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

        //값이 0보다 큰 수 중 가장 오른쪽의 인덱스로 갱신
        while (delivery_pos >= 0 && deliveries[delivery_pos] == 0)
            delivery_pos--;
        while (pickup_pos >= 0 && pickups[pickup_pos] == 0)
            pickup_pos--;

        //delivery_pos, pickup_pos중 더 큰 값*2로 갱신
        //(어짜피 언젠가는 가야하기 때문에 더 먼곳을 기준으로 왕복
        answer += max(delivery_pos + 1, pickup_pos + 1) * 2;

        //cap을 기준으로 배달 배열, 수집 배열을 각각 갱신
        //(배달을 끝낸 시점(수집 전)에 트럭에 상자가 없게끔만 하면되므로
        // 배달에서 최대 cap번 뺼 수 있을 만큼 빼고
        // 수집에서도 최대 cap번 뺄 수 있을 만큼 뺀다.)
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
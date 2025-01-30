#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;

    //동생의 토핑 종류 개수, 토핑별 개수를 저장할 맵 생성
    //(처음엔 동생이 롤케이크 전체를 먹는다고 가정)
    int cases_b = 0;
    unordered_map<int, int> mem_b;
    for (int i = 0; i < topping.size(); ++i) {
        int value = topping[i];

        if (mem_b.find(value) == mem_b.end())
            cases_b++;

        mem_b[value]++;
    }


    //철수도 똑같이 종류 변수, 토핑 별 개수를 저장할 맵 생성
    //점차 형의 지분을 넓혀가며 관련 변수들을 갱신
    //->동생의 종류 == 형의 종류 => answer(방법수)++
    int cases_a = 0;
    unordered_map<int, int> mem_a;
    for (int i = 0; i < topping.size(); ++i) {
        int value = topping[i];

        //철수거 갱신
        if (mem_a.find(value) == mem_a.end())
            cases_a++;
        mem_a[value]++;

        //동생거 갱신
        if (--mem_b[value] == 0) {
            cases_b--;
            mem_b.erase(value);
        }

        if (cases_a == cases_b) answer++;

    }
    return answer;
}
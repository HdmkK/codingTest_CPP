#include <string>
#include <vector>
#include <iostream>
#include <bitset>
using namespace std;


vector<int> solution(string s) {
    vector<int> answer;
    
    int transform = 0;
    int removedZeros = 0;

    while (s != "1") {
        transform++;

        //0의 개수 업데이트
        removedZeros += count(s.begin(), s.end(), '0');

        int onesCount = count(s.begin(), s.end(), '1');
        s = bitset<32>(onesCount).to_string();
        s = s.substr(s.find('1'));
    }

    return { transform, removedZeros };
}
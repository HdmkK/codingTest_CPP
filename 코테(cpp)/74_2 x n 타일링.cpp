#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    vector<int> mem = { 0, 1, 2 };
    for (int i = 3; i <= n; ++i) {
        mem.push_back((mem[i - 1] + mem[i - 2]) % 1000000007);
    }
    return mem[n];
}
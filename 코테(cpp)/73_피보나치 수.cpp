#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, int> mem;

int fn(int n) {
    if (n == 0 || n == 1) return n;

    if (mem.count(n - 1) == 0)
        mem[n - 1] = fn(n - 1) % 1234567;
    if (mem.count(n - 2) == 0)
        mem[n - 2] = fn(n - 2) % 1234567;

    return mem[n - 1] + mem[n - 2];
}

int solution(int n) {
    int answer = 0;
    answer = fn(n) % 1234567;
    return answer;
}
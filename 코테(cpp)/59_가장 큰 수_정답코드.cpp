#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool compare(const string& a, const string& b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";

    if (accumulate(numbers.begin(), numbers.end(), 0) == 0) return "0";
    vector<string> mem;
    for (int n : numbers) {
        mem.push_back(to_string(n));
    }
    sort(mem.begin(), mem.end(), compare);
    for (string s : mem) {
        answer += s;
    }
    return answer;
}
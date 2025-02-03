#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#include <numeric>
using namespace std;

bool compare(const tuple<int, string>& a, const tuple<int, string>& b) {
    return get<1>(a) > get<1>(b);
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<tuple<int, string>> mem;

    if (accumulate(numbers.begin(), numbers.end(), 0) == 0) return "0";


    for (int i = 0; i < numbers.size(); ++i) {
        string s = "";
        for (int j = 0; j < 3; ++j)
            s += to_string(numbers[i]);
        mem.push_back({ i, s });
    }

    sort(mem.begin(), mem.end(), compare);

    for (auto& [idx, s] : mem) {
        answer += to_string(numbers[idx]);
    }

    return answer;
}
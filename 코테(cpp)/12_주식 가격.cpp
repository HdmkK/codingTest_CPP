#include <string>
#include <vector>
#include <stack>
#include <array>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    for (auto i : prices) {
        answer.push_back(0);
    }

    stack<array<int, 2>> st;

    int price;
    int N;
    N = prices.size();

    for (int i = 0; i < N; ++i) {
        price = prices[i];

        while (!st.empty() && st.top()[1] > price) {
            array<int, 2> tmp = st.top();
            int j = tmp[0];
            answer[j] = i - j;
            st.pop();
        }

        st.push(array<int, 2>{i, price});
    }

    while (!st.empty()) {
        array<int, 2> tmp = st.top();
        int i = tmp[0];
        answer[i] = (N - 1) - i;
        st.pop();
    }
    return answer;
}
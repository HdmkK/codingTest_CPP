#include <iostream>
#include <stack>
#include <vector>
#include <tuple>
using namespace std;

int N;
vector<int> A;
vector<int> answer;

int main() {

	cin >> N;
	A.assign(N + 1, 0);
	answer.assign(N + 1, 0);

	for (int i = 1; i <= N; ++i) {
		int input;
		cin >> input;
		A[i] = input;
	}

	stack<pair<int, int>> st;

	for (int i = 1; i <= N; ++i) {

		while (st.size() > 0 && A[i] > st.top().first)
			st.pop();

		if (st.size() > 0)
			answer[i] = st.top().second;

		st.push(make_pair(A[i], i));
	}

	for (int i = 1; i < answer.size(); ++i)
		cout << answer[i] << " ";
	return 0;
}



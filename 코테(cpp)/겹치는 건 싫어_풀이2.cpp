#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;

deque<int> dq;
vector<int> mem(2000000, 0);
int N, K;
int ans = 0;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;

	for (int i = 0; i < N; ++i) {
		int input;
		cin >> input;

		while (dq.size() > 0 && mem[input] >= K) {
			int front = dq.front();
			dq.pop_front();

			mem[front]--;
		}

		dq.push_back(input);
		mem[input]++;

		ans = max(ans, static_cast<int>(dq.size()));
	}

	cout << ans << '\n';
	return 0;
}



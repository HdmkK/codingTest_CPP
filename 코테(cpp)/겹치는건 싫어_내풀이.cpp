#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <deque>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	vector<int> nums;
	int ans = 0;

	cin >> N >> K;

	for (int i = 0; i < N; ++i) {
		int input;
		cin >> input;
		nums.push_back(input);
	}

	deque<int> dq;
	unordered_map<int, int> mem;

	for (int i = 0; i < N; ++i) {

		if (mem[nums[i]] == K) {
			ans = max(ans, static_cast<int>(dq.size()));

			while (dq.front() != nums[i]) {
				mem[dq.front()]--;
				dq.pop_front();
			}
			mem[dq.front()]--;
			dq.pop_front();
		}

		dq.push_back(nums[i]);
		mem[nums[i]]++;
	}

	ans = max(ans, static_cast<int>(dq.size()));

	cout << ans << endl;
	return 0;
}



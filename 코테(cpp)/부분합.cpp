#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
using namespace std;

int N, S;
vector<int> nums;
int INF = numeric_limits<int>::max();

int main() {

	int answer = INF;

	cin >> N >> S;

	for (int i = 0; i < N; ++i) {
		int input;
		cin >> input;
		nums.push_back(input);
	}

	int start = 0, end = 0;
	long long sum = nums[0];

	while (true) {

		if (sum < S) {
			if (end == N - 1) break;

			sum += nums[++end];
			continue;
		}

		if (sum >= S) {
			answer = min(answer, end - start + 1);

			if (start == N - 1) break;

			sum -= nums[start++];
		}
	}

	//cout << "±æÀÌ : " << answer << endl;
	if (answer == INF) answer = 0;
	cout << answer << endl;

	return 0;
}
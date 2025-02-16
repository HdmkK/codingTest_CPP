#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<long long> budgetRequests;
long long budget;

int main() {

	cin >> N;
	long long answer = -1;
	long long sum = 0;

	for (int i = 0; i < N; ++i) {
		long long input;
		cin >> input;
		sum += input;
		budgetRequests.push_back(input);
	}
	cin >> budget;

	sort(budgetRequests.begin(), budgetRequests.end(), greater<int>());

	if (sum <= budget) {
		cout << budgetRequests[0] << endl;
		return 0;
	}

	int n = 0;

	for (int cur = 0; cur < N; ++cur) {

		if (cur > 0) sum += (-1 * (n * budgetRequests[cur - 1]) + (n * budgetRequests[cur]));

		if (sum > budget) {
			n++;
			continue;
		}
		else {

			long long rest = budget - sum;
			//cout << rest << ", " << n << endl;
			answer = budgetRequests[cur] + (rest / n);
			break;
		}
	}

	if (answer == -1) {
		cout << budget / N << endl;
	}
	else {
		cout << answer << endl;
	}

	return 0;
}

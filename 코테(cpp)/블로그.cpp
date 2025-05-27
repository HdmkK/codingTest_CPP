#include <iostream>
#include <vector>

using namespace std;

int main() {

	int N, X;
	cin >> N >> X;
	vector<int> A(N);

	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}

	int maxValue = 0;
	int cnt = 0;
	int sum = 0;

	for (int i = 0; i < X; ++i) {
		sum += A[i];
	}

	cnt = 1;
	maxValue = sum;

	for (int i = 1; i <= N - X; ++i) {
		sum -= A[i - 1];
		sum += A[i + X - 1];

		if (sum > maxValue) {
			cnt = 1;
			maxValue = sum;
		}
		else if (sum == maxValue) {
			cnt++;
		}
	}

	if (maxValue == 0) {
		cout << "SAD" << endl;
	}
	else {
		cout << maxValue << endl;
		cout << cnt << endl;
	}
	return 0;
}
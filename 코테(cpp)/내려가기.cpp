#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main() {

	cin >> N;
	int A[3];
	int dpMax[3];
	int dpMin[3];
	int tmpMax[3];
	int tmpMin[3];

	cin >> A[0] >> A[1] >> A[2];

	for (int i = 0; i < 3; ++i) {
		dpMax[i] = A[i];
		dpMin[i] = A[i];
	}

	for (int x = 1; x < N; ++x) {

		cin >> A[0] >> A[1] >> A[2];

		tmpMax[0] = max(dpMax[0], dpMax[1]) + A[0];
		tmpMax[1] = max({ dpMax[0], dpMax[1], dpMax[2] }) + A[1];
		tmpMax[2] = max(dpMax[1], dpMax[2]) + A[2];

		tmpMin[0] = min(dpMin[0], dpMin[1]) + A[0];
		tmpMin[1] = min({ dpMin[0], dpMin[1], dpMin[2] }) + A[1];
		tmpMin[2] = min(dpMin[1], dpMin[2]) + A[2];

		for (int i = 0; i < 3; ++i) {
			dpMax[i] = tmpMax[i];
			dpMin[i] = tmpMin[i];
		}
	}

	int max_v = max({ dpMax[0], dpMax[1], dpMax[2] });
	int min_v = min({ dpMin[0], dpMin[1], dpMin[2] });

	cout << max_v << " " << min_v;
}


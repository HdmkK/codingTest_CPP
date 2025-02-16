#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int N;
int peopleNum;
int main() {

	cin >> N; //스위치 개수
	vector<int> switches(N + 1);
	for (int i = 1; i <= N; ++i) {
		int input;
		cin >> input;
		switches[i] = input;
	}

	cin >> peopleNum;
	vector<tuple<int, int>> people;
	for (int i = 0; i < peopleNum; ++i) {
		int a, b;
		cin >> a >> b;
		people.push_back({ a, b });
	}


	for (auto& [gender, num] : people) {
		if (gender == 1) {
			int idx = num;

			while (idx <= N) {
				switches[idx] ^= 1;
				idx += num;
			}
		}
		else if (gender == 2) {
			int idx = 1;
			switches[num] ^= 1;
			while (num - idx >= 1 && num + idx <= N && switches[num - idx] == switches[num + idx]) {
				switches[num - idx] ^= 1;
				switches[num + idx] ^= 1;
				idx++;
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		cout << switches[i] << " ";

		if (i % 20 == 0)
			cout << endl;
	}


	return 0;
}
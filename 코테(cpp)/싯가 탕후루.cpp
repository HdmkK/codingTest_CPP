#include <iostream>

#define MAX 1000000
int PRICE[MAX + 100];
unsigned long long N;

using namespace std;

int main() {

	cin >> N;
	for (int i = 0; i < N; ++i) {
		int input;
		cin >> input;
		PRICE[input]++;
	}

	unsigned long long maxV = 0;
	int curPrice = 0;
	bool flag = false;
	for (unsigned long long p = 1; p <= MAX; ++p) {

		unsigned long long m = N * p;
		N -= PRICE[p];
		if (N < 0) flag = true;

		if (maxV < m) {
			maxV = m;
			curPrice = p;
		}
	}

	cout << maxV << " " << curPrice << endl;
	if (flag)
		cout << "À½¼ö°¡ ³ª¿È" << endl;

	return 0;
}
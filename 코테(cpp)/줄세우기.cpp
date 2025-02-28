#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {

	for (int k = 0; k < 3; k++) {
		int N;
		vector<int> A;

		cin >> N;
		vector<int> A;
		A.push_back(0);
		cout << "hell" << endl;
		int sum = 0;
		int coinNum = 0;
		for (int i = 0; i < N; ++i) {
			
			int coin, n;
			cin >> coin >> n;

			sum += coin * n;
			coinNum += n;

			for (int j = 0; j < n; ++j)
				A.push_back(coin);
		}

		//Á¤·Ä
		sort(A.begin(), A.end());

		int halfSum = sum / 2;

		vector<vector<bool>> dp(coinNum + 1, vector<bool>(halfSum, false));

		for (int x = 1; x <= coinNum; ++x) {
			for (int total = 1; total <= halfSum; ++total) {
				dp[x][total] = dp[x - 1][total] || dp[x - 1][total - A[x]];
			}
		}

		cout << ((dp[coinNum][halfSum]) ? 1 : 0) << endl;
	}

	return 0;
}



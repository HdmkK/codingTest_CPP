#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
vector<vector<int>> A;
vector<vector<long long>> dp;
int main() {

	cin >> N;
	A.assign(N, vector<int>(N));
	dp.assign(N, vector<long long>(N, 0));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int input;
			cin >> input;
			A[i][j] = input;
		}
	}


	dp[0][0] = 1;

	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {

			if (dp[x][y] == 0) continue;
			if (x == N - 1 && y == N - 1) continue;
			int n_x, n_y;

			//오른쪽
			n_x = x;
			n_y = y + A[x][y];

			if (n_x >= 0 && n_x < N && n_y >= 0 && n_y < N) {
				dp[n_x][n_y] += dp[x][y];
			}

			//아래쪽
			n_x = x + A[x][y];
			n_y = y;

			if (n_x >= 0 && n_x < N && n_y >= 0 && n_y < N) {
				dp[n_x][n_y] += dp[x][y];
			}

			/*for (int x = 0; x < N; ++x) {
				for (int y = 0; y < N; ++y) {
					cout << dp[x][y] << " ";
				}
				cout << endl;
			}
			cout << "===" << endl;*/
		}
	}



	cout << dp[N - 1][N - 1] << endl;

	return 0;
}


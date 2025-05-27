#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

#define MAX 100000

int N;
int startX, startY;
vector<vector<long long>> DP;
vector<tuple<int, int>> costumerXY;
int dx[] = { 0, 0, 0, 1, -1 };
int dy[] = { 0, 1, -1, 0, 0 };

int main() {

	cin >> N;

	cin >> startX >> startY;

	DP.assign(N, vector<long long>(5, 10000000000));
	for (int i = 0; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		costumerXY.push_back({ a, b });
	}


	auto [s_x, s_y] = costumerXY[0];

	//첫 번째 손님 DP 초기화
	for (int i = 0; i < 5; ++i) {
		int n_x = s_x + dx[i];
		int n_y = s_y + dy[i];

		if (n_x<1 || n_x>MAX || n_y<1 || n_y>MAX) continue;


		DP[0][i] = abs(n_x - startX) + abs(n_y - startY);

	}


	//두 번째 손님 부터 시작
	for (int i = 1; i < N; ++i) {

		auto [p_std_x, p_std_y] = costumerXY[i - 1];
		auto [std_x, std_y] = costumerXY[i];

		for (int j = 0; j < 5; ++j) {
			//기준점 구하기

			int c_x = p_std_x + dx[j];
			int c_y = p_std_y + dy[j];

			if (c_x<1 || c_x>MAX || c_y<1 || c_y>MAX) continue;

			for (int k = 0; k < 5; ++k) {
				//다음 점

				int n_x = std_x + dx[k];
				int n_y = std_y + dy[k];

				if (n_x<1 || n_x>MAX || n_y < 1 || n_y > MAX) continue;

				DP[i][k] = min(DP[i][k], abs(n_x - c_x) + abs(n_y - c_y) + DP[i - 1][j]);
			}
		}

	}


	//마지막 손님 DP 5개 중 최소
	cout << *min_element(DP[N - 1].begin(), DP[N - 1].end()) << endl;


	return 0;
}
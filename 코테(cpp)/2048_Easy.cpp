#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
using namespace std;

int N;
vector<vector<int>> A;
int maxVal = 0;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { -1, 1, 0, 0 };


void dfs(vector<vector<int>>& map, int cnt) {

	if (cnt >= 5) return;


	vector<vector<int>> copyMap;
	vector<vector<bool>> merged;

	//왼쪽
	copyMap = map;
	merged.assign(N, vector<bool>(N, false));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			int n_x = x;
			int n_y = y;

			while (true) {

				n_x += dx[0];
				n_y += dy[0];

				//범위밖
				if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= N) break;

				if (copyMap[n_x][n_y] > 0) {
					if (copyMap[n_x][n_y] == copyMap[n_x - dx[0]][n_y - dy[0]]
						&& not merged[n_x][n_y]) {
						merged[n_x][n_y] = true;
						copyMap[n_x][n_y] *= 2;
						copyMap[n_x - dx[0]][n_y - dy[0]] = 0;
						maxVal = max(maxVal, copyMap[n_x][n_y]);
					}
					break;
				}

				copyMap[n_x][n_y] = copyMap[n_x - dx[0]][n_y - dy[0]];
				copyMap[n_x - dx[0]][n_y - dy[0]] = 0;
				maxVal = max(maxVal, copyMap[n_x][n_y]);
			}
		}
	}


	dfs(copyMap, cnt + 1);


	//오른쪽
	copyMap = map;
	merged.assign(N, vector<bool>(N, false));
	for (int y = N - 1; y >= 0; --y) {
		for (int x = 0; x < N; ++x) {
			int n_x = x;
			int n_y = y;

			while (true) {

				n_x += dx[1];
				n_y += dy[1];

				//범위밖
				if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= N) break;

				if (copyMap[n_x][n_y] > 0) {
					if (copyMap[n_x][n_y] == copyMap[n_x - dx[1]][n_y - dy[1]]
						&& not merged[n_x][n_y]) {
						merged[n_x][n_y] = true;
						copyMap[n_x][n_y] *= 2;
						copyMap[n_x - dx[1]][n_y - dy[1]] = 0;
						maxVal = max(maxVal, copyMap[n_x][n_y]);
					}
					break;
				}

				copyMap[n_x][n_y] = copyMap[n_x - dx[1]][n_y - dy[1]];
				copyMap[n_x - dx[1]][n_y - dy[1]] = 0;
				maxVal = max(maxVal, copyMap[n_x][n_y]);
			}
		}
	}


	dfs(copyMap, cnt + 1);



	//아랫쪽
	copyMap = map;
	merged.assign(N, vector<bool>(N, false));
	for (int x = N - 1; x >= 0; --x) {
		for (int y = 0; y < N; ++y) {
			int n_x = x;
			int n_y = y;

			while (true) {

				n_x += dx[2];
				n_y += dy[2];

				//범위밖
				if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= N) break;

				if (copyMap[n_x][n_y] > 0) {
					if (copyMap[n_x][n_y] == copyMap[n_x - dx[2]][n_y - dy[2]]
						&& not merged[n_x][n_y]) {
						merged[n_x][n_y] = true;
						copyMap[n_x][n_y] *= 2;
						copyMap[n_x - dx[2]][n_y - dy[2]] = 0;
						maxVal = max(maxVal, copyMap[n_x][n_y]);
					}
					break;
				}

				copyMap[n_x][n_y] = copyMap[n_x - dx[2]][n_y - dy[2]];
				copyMap[n_x - dx[2]][n_y - dy[2]] = 0;
				maxVal = max(maxVal, copyMap[n_x][n_y]);
			}
		}
	}

	dfs(copyMap, cnt + 1);


	//윗쪽
	copyMap = map;
	merged.assign(N, vector<bool>(N, false));
	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			int n_x = x;
			int n_y = y;

			while (true) {

				n_x += dx[3];
				n_y += dy[3];

				//범위밖
				if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= N) break;

				if (copyMap[n_x][n_y] > 0) {
					if (copyMap[n_x][n_y] == copyMap[n_x - dx[3]][n_y - dy[3]]
						&& not merged[n_x][n_y]) {
						merged[n_x][n_y] = true;
						copyMap[n_x][n_y] *= 2;
						copyMap[n_x - dx[3]][n_y - dy[3]] = 0;
						maxVal = max(maxVal, copyMap[n_x][n_y]);
					}
					break;
				}

				copyMap[n_x][n_y] = copyMap[n_x - dx[3]][n_y - dy[3]];
				copyMap[n_x - dx[3]][n_y - dy[3]] = 0;
				maxVal = max(maxVal, copyMap[n_x][n_y]);
			}
		}
	}

	dfs(copyMap, cnt + 1);
}

int main() {

	cin >> N;
	A.assign(N, vector<int>(N));
	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			cin >> A[x][y];
			maxVal = max(maxVal, A[x][y]);
		}
	}

	dfs(A, 0);
	cout << maxVal << endl;



	return 0;
}
#include <iostream>

using namespace std;

int A[6][6];
char answer[6][6];
int N;

int dx[] = { -1, -1, 1, 1 };
int dy[] = { 1, -1, -1, 1 };


void dfs(int x, int y, int k, int r, int d) {
	if (k == 11) return;

	if (A[x][y] > k)
		A[x][y] = k;

	if ((x == 0 && y == 0)
		|| (x == 5 && y == 0)
		|| (x == 0 && y == 5)
		|| (x == 5 && y == 5)) {
		if (r == 1)
			d = (d + 1) % 4;
		else if (r == -1)
			d = (d - 1 < 0) ? 3 : d - 1;
	}

	if (x == 0 || x == 5 || y == 0 || y == 5) {
		if (r == 1)
			d = (d + 1) % 4;
		else if (r == -1)
			d = (d - 1 < 0) ? 3 : d - 1;
	}

	int n_x = x + dx[d];
	int n_y = y + dy[d];
	dfs(n_x, n_y, k + 1, r, d);

}

int main() {

	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			A[i][j] = 100;
		}
	}

	cin >> N;
	for (int i = 0; i < N; ++i) {
		int start;
		char direction;
		cin >> start >> direction;

		int r = 1, d = 0;

		if (direction == 'R') {

			r = 1;

			if (start == 0) {
				d = 2;
			}
			else {
				d = 3;
			}
		}

		else if (direction == 'L') {

			r = -1;

			if (start == 5) {
				d = 3;
			}
			else {
				d = 2;
			}

		}


		dfs(5, start, 1, r, d);
	}


	for (int x = 0; x < 6; ++x) {
		for (int y = 0; y < 6; ++y) {
			if (A[x][y] == 100)
				cout << '_';
			else
				cout << A[x][y];
		}
		cout << '\n';
	}


	return 0;
}
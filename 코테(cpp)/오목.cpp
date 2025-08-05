#include <iostream>
#include <vector>
using namespace std;

int A[19][19];

int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };


int r_t_x = 100, r_t_y = 100;
int win = 0;

void calc() {


	for (int x = 0; x < 19; ++x) {
		for (int y = 0; y < 19; ++y) {

			if (A[x][y] == 0) continue;

			int color = A[x][y];

			for (int d = 0; d <= 3; ++d) {


				int sum = 1;
				int n_x = x;
				int n_y = y;

				int t_x = x, t_y = y;

				while (true) {
					n_x += dx[d];
					n_y += dy[d];

					if (n_x < 0 || n_x >= 19 || n_y < 0 || n_y >= 19) break;
					if (A[n_x][n_y] != color) break;

					sum += 1;

					if (n_y < t_y) {
						t_x = n_x;
						t_y = n_y;
					}
					else if (n_y == t_y && n_x < t_x) {
						t_x = n_x;
						t_y = n_y;
					}
				}

				n_x = x;
				n_y = y;

				while (true) {
					n_x += dx[d + 4];
					n_y += dy[d + 4];

					if (n_x < 0 || n_x >= 19 || n_y < 0 || n_y >= 19) break;
					if (A[n_x][n_y] != color) break;

					sum += 1;

					if (n_y < t_y) {
						t_x = n_x;
						t_y = n_y;
					}
					else if (n_y == t_y && n_x < t_x) {
						t_x = n_x;
						t_y = n_y;
					}
				}
				if (sum == 5) {
					r_t_x = t_x;
					r_t_y = t_y;
					win = color;
					return;
				}
			}

		}
	}
}

int main() {

	for (int x = 0; x < 19; ++x) {
		for (int y = 0; y < 19; ++y) {
			cin >> A[x][y];
		}
	}



	calc();

	cout << win << endl;
	if (win > 0) {
		cout << r_t_x + 1 << " " << r_t_y + 1 << endl;
	}


	return 0;
}
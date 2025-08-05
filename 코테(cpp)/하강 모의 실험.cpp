#include <iostream>

using namespace std;

int T;
int N;

int A[500][500];

void down() {

	for (int y = 0; y < N; ++y) {
		if (A[0][y] == 0) continue;//1행에 블럭 없으면 pass

		int b_x = 0;
		int b_y = y;
		int cnt = 1;
		double c_power = 1.0;

		while (true) {
			//cout << "[" << b_y << "] b_x : " << b_x << ", cnt : " << cnt << endl;
			int n_x = b_x + 1;
			int n_y = b_y;

			if (n_x >= N) {
				b_x = N - 1;
				break;
			}

			if (A[n_x][n_y] == 0) {
				c_power *= 1.9;
				b_x += 1;
				continue;
			}


			double resistance = 0;

			while (n_x < N && A[n_x][n_y] == 1) {
				resistance += 1;
				n_x += 1;
			}

			//cout << "[" << b_y << "] c_power : " << c_power << ", resistance : " << resistance << endl;
			if (c_power > resistance) {
				c_power += resistance;
				cnt += resistance;
				b_x = n_x - 1;
			}
			else
				break;
		}

		//cout << "[" << b_y << "] b_x : " << b_x << ", cnt : " << cnt << endl;
		while (b_x >= 0) {
			if (cnt > 0) A[b_x][y] = 1;
			else A[b_x][y] = 0;

			--cnt;
			--b_x;
		}
	}
}


void right() {

	for (int x = 0; x < N; ++x) {
		if (A[x][0] == 0) continue;//1열에 블럭 없으면 pass

		int b_x = x;
		int b_y = 0;
		int cnt = 1;
		double c_power = 1.0;

		while (true) {
			//cout << "[" << b_y << "] b_x : " << b_x << ", cnt : " << cnt << endl;
			int n_x = b_x;
			int n_y = b_y + 1;

			if (n_y >= N) {
				b_y = N - 1;
				break;
			}

			if (A[n_x][n_y] == 0) {
				c_power *= 1.9;
				b_y += 1;
				continue;
			}


			double resistance = 0;

			while (n_y < N && A[n_x][n_y] == 1) {
				resistance += 1;
				n_y += 1;
			}

			//cout << "[" << b_y << "] c_power : " << c_power << ", resistance : " << resistance << endl;
			if (c_power > resistance) {
				c_power += resistance;
				cnt += resistance;
				b_y = n_y - 1;
			}
			else
				break;
		}

		//cout << "[" << b_y << "] b_x : " << b_x << ", cnt : " << cnt << endl;
		while (b_y >= 0) {
			if (cnt > 0) A[x][b_y] = 1;
			else A[x][b_y] = 0;

			--cnt;
			--b_y;
		}
	}

}

void printA() {
	cout << "==============" << endl;
	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			cout << A[x][y] << " ";
		}
		cout << endl;
	}
}

int calc1() {
	int sum = 0;
	for (int y = 0; y < N; ++y) {
		sum += A[N - 1][y];
	}

	return sum;
}

int calc2() {
	int sum = 0;
	for (int x = 0; x < N; ++x) {
		sum += A[x][N - 1];
	}

	return sum;
}



int main() {
	cin >> T;




	for (int test_case = 1; test_case <= T; ++test_case) {

		cin >> N;
		for (int x = 0; x < N; ++x) {
			for (int y = 0; y < N; ++y) {
				cin >> A[x][y];
			}
		}

		down();
		//printA();
		right();
		//printA();

		cout << "#" << test_case << " " << calc1() << " " << calc2() << endl;
	}

	return 0;
}
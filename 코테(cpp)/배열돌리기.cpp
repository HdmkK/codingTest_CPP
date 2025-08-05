#include <iostream>
#include <vector>
#include <tuple>
#include <limits>
using namespace std;

int T;
int N, M, K;
vector<vector<int>> A;

vector<tuple<int, int, int>> ops;
vector<int> opOrder;
bool mem[5];

int minV;


void printA(vector<vector<int>>& A) {
	cout << "=========================" << endl;
	for (int x = 0; x < A.size(); ++x) {
		for (int y = 0; y < A[0].size(); ++y) {
			cout << A[x][y] << " ";
		}
		cout << endl;
	}
}

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

void rotate(vector<vector<int>>& A) {
	int W = A.size();

	for (int k = 0; k < W / 2; ++k) {

		int s_x = k;
		int s_y = k;

		int pre = A[s_x][s_y];
		int n_x = s_x;
		int n_y = s_y;
		int d = 0;

		while (true) {
			//cout << n_x << ", " << n_y << endl;
			n_x += dx[d];
			n_y += dy[d];

			if (n_x == s_x && n_y == s_y) break;

			if (n_x < 0 + k || n_x >= W - k || n_y < 0 + k || n_y >= W - k) {
				n_x -= dx[d];
				n_y -= dy[d];
				d = (d + 1) % 4;
				continue;
			}


			int temp = A[n_x][n_y];
			A[n_x][n_y] = pre;
			pre = temp;
		}

		A[s_x][s_y] = pre;

	}
}

int calc() {
	auto copyA = A;
	int minV = numeric_limits<int>::max();

	//연산을 차례대로 적용
	for (int i : opOrder) {
		auto& [r, c, s] = ops[i];

		vector<vector<int>> temp(1 + 2 * s, vector<int>(1 + 2 * s, 0));

		for (int x = r - s; x <= r + s; ++x) {
			for (int y = c - s; y <= c + s; ++y) {

				int relX = x - (r - s);
				int relY = y - (c - s);
				temp[relX][relY] = copyA[x][y];
			}
		}

		rotate(temp);


		for (int x = 0; x < temp.size(); ++x) {
			for (int y = 0; y < temp.size(); ++y) {
				int abX = x + (r - s);
				int abY = y + (c - s);
				copyA[abX][abY] = temp[x][y];
			}
		}


		//printA(temp);
	}


	for (int i = 1; i <= N; ++i) {
		int sum = 0;
		for (int j = 1; j <= M; ++j) {
			sum += copyA[i][j];
		}
		minV = min(minV, sum);
	}


	return minV;
}

void dfs() {

	if (opOrder.size() == K) {
		int ret = calc();
		minV = min(minV, ret);
		return;
	}

	for (int i = 0; i < K; ++i) {
		if (mem[i]) continue;

		opOrder.push_back(i);
		mem[i] = true;
		dfs();
		mem[i] = false;
		opOrder.pop_back();
	}
}

void init() {
	A.assign(N + 2, vector<int>(M + 2, 0));
	ops.clear();
	minV = numeric_limits<int>::max();
}

int main() {
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case) {
		cin >> N >> M >> K;

		init();

		for (int x = 1; x <= N; ++x) {
			for (int y = 1; y <= M; ++y) {
				cin >> A[x][y];
			}
		}

		int r, c, s;
		for (int i = 0; i < K; ++i) {
			cin >> r >> c >> s;
			ops.push_back({ r, c, s });
		}

		dfs();
		cout << "#" << test_case << " " << minV << endl;
	}



	return 0;
}
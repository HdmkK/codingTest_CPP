#include <iostream>
#include <vector>

using namespace std;

int N, M, H;
vector<vector<int>> ladder;

void dfs(int s_x, int s_y, int cnt, int maxDepth);
bool check();

int main() {

	cin >> N >> M >> H;

	ladder.assign(H + 1, vector<int>(N + 2, 0));

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		ladder[a][b] = 1;
	}

	for (int n = 0; n <= 3; ++n) {
		dfs(1, 1, 0, n);
	}

	cout << -1 << endl;

	return 0;
}


void dfs(int s_x, int s_y, int cnt, int maxDepth) {

	if (cnt == maxDepth) {
		if (check()) {
			cout << maxDepth << endl;
			exit(0);
		}

		return;
	}


	//이차원 배열에서의 백트래킹!!
	for (int x = s_x; x <= H; ++x) {
		for (int y = (s_x == x) ? s_y : 1; y < N; ++y) {

			if (ladder[x][y - 1] || ladder[x][y] || ladder[x][y + 1]) continue;

			ladder[x][y] = 1;

			dfs(x, y, cnt + 1, maxDepth);

			ladder[x][y] = 0;
		}
	}
}

bool check() {

	for (int start = 1; start <= N; ++start) {
		int end = start;
		for (int i = 1; i <= H; ++i) {
			if (ladder[i][end]) end++;
			else if (ladder[i][end - 1]) end--;
		}

		if (start != end) return false;
	}

	return true;
}
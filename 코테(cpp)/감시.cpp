#include <iostream>
#include <algorithm>
using namespace std;

void input();

int N, M, K = 0;
int A[8][8];
bool mem[8][8];
int originSafeArea = 0;


int cctv_x[8];
int cctv_y[8];
int cctv_d[8];

int minV = 65;


//동남서북
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

bool isValidXY(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M) return false;
	else return true;
}


int checkStraitFromCCTV(int d, int s_x, int s_y) {

	int sum = 0;

	int n_x = s_x + dx[d];
	int n_y = s_y + dy[d];

	while (isValidXY(n_x, n_y) && A[n_x][n_y] < 6) {
		if (A[n_x][n_y] == 0 && not mem[n_x][n_y]) {
			sum++;
			mem[n_x][n_y] = true;
		}
		n_x += dx[d];
		n_y += dy[d];
	}
	return sum;
}

int act_cctv_1(int d, int s_x, int s_y) {

	int sum = 0;

	sum += checkStraitFromCCTV(d, s_x, s_y);

	return sum;
}


int act_cctv_2(int d, int s_x, int s_y) {

	if (d == 2 || d == 3) return 0;//중복 방지

	int sum = 0;

	//한방향
	sum += checkStraitFromCCTV(d, s_x, s_y);

	//맞은편 방향
	sum += checkStraitFromCCTV((d + 2) % 4, s_x, s_y);

	return sum;
}


int act_cctv_3(int d, int s_x, int s_y) {

	int sum = 0;


	//첫번째 방향
	sum += checkStraitFromCCTV(d, s_x, s_y);

	//다음 방향
	sum += checkStraitFromCCTV((d + 1) % 4, s_x, s_y);

	return sum;
}


int act_cctv_4(int d, int s_x, int s_y) {

	int sum = 0;


	//첫번째 방향
	sum += checkStraitFromCCTV(d, s_x, s_y);

	//다음 방향
	sum += checkStraitFromCCTV((d + 1) % 4, s_x, s_y);

	//그 다음 방향
	sum += checkStraitFromCCTV((d + 2) % 4, s_x, s_y);

	return sum;
}


int act_cctv_5(int d, int s_x, int s_y) {
	if (d != 0) return 0;

	int sum = 0;

	for (int k = 0; k < 4; ++k)
		sum += checkStraitFromCCTV((d + k) % 4, s_x, s_y);

	return sum;
}



//완성된 CCTV 방향 조합으로 시뮬레이션
void calc() {

	fill(&mem[0][0], &mem[0][0] + 64, false);

	int sum = 0;
	for (int i = 0; i < K; ++i) {

		switch (A[cctv_x[i]][cctv_y[i]]) {
		case 1:
			sum += act_cctv_1(cctv_d[i], cctv_x[i], cctv_y[i]);
			break;
		case 2:
			sum += act_cctv_2(cctv_d[i], cctv_x[i], cctv_y[i]);
			break;
		case 3:
			sum += act_cctv_3(cctv_d[i], cctv_x[i], cctv_y[i]);
			break;
		case 4:
			sum += act_cctv_4(cctv_d[i], cctv_x[i], cctv_y[i]);
			break;
		case 5:
			sum += act_cctv_5(cctv_d[i], cctv_x[i], cctv_y[i]);
			break;
		}

	}


	int ret = originSafeArea - sum;
	minV = min(minV, ret);

}

//CCTV 방향 조합 생성
void dfs(int i) {

	if (i == K) {
		calc();
		return;
	}

	for (int d = 0; d < 4; ++d) {
		cctv_d[i] = d;
		dfs(i + 1);
	}
}


int main() {

	input();

	dfs(0);

	cout << minV << endl;
	return 0;
}

void input() {
	cin >> N >> M;
	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < M; ++y) {
			cin >> A[x][y];

			if (A[x][y] == 0)
				originSafeArea++;

			if (A[x][y] >= 1 && A[x][y] <= 5) {
				cctv_x[K] = x;
				cctv_y[K] = y;
				K++;
			}
		}
	}
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
#include <queue>
#include <tuple>
using namespace std;


int N;
int K;
char map[100][100];
bool visited[100][100];
int L;
int L_timeInfo[100];
char L_directionInfo[100];
int L_idx = 0;
int seconds = 0;

//동 0
//남 1
//서 2
//북 3
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

void input();

void printAll() {
	cout << "===============" << endl;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (visited[i][j]) {
				cout << "O" << " ";
				continue;
			}
			if (map[i][j] == 'A') {
				cout << "A" << " ";
				continue;
			}
			else cout << "." << " ";
		}
		cout << endl;
	}
}

int main() {

	input();


	queue<tuple<int, int>> q;
	q.push({ 0, 0 });
	visited[0][0];

	int cur_d = 0;

	while (!q.empty())
	{
		seconds++;

		auto& [head_x, head_y] = q.back();

		int n_x = head_x + dx[cur_d];
		int n_y = head_y + dy[cur_d];


		if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= N) break;
		if (visited[n_x][n_y]) break;


		//방향 변환 조건 검사
		int cond_time = L_timeInfo[L_idx];
		char cond_direction = L_directionInfo[L_idx];

		if (seconds == cond_time) {

			if (cond_direction == 'L') {
				cur_d--;
				if (cur_d < 0) cur_d = 3;
			}
			else if (cond_direction == 'D') {
				cur_d = (cur_d + 1) % 4;
			}

			L_idx++;
		}

		//일단 머리는 뻗음
		q.push({ n_x, n_y });
		visited[n_x][n_y] = true;

		//사과 먹음
		if (map[n_x][n_y] == 'A') {
			map[n_x][n_y] = '.';
		}
		else {
			auto [tail_x, tail_y] = q.front();
			q.pop();
			visited[tail_x][tail_y] = false;
		}

		//printAll();

	}


	cout << seconds;

	return 0;
}

void input() {
	cin >> N;
	cin >> K;
	for (int i = 0; i < K; ++i) {
		int x, y;
		cin >> x >> y;
		map[x - 1][y - 1] = 'A';
	}

	cin >> L;
	for (int i = 0; i < L; ++i) {
		cin >> L_timeInfo[i] >> L_directionInfo[i];
	}
}
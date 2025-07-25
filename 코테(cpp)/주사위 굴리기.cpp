#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
#include <queue>
#include <tuple>
#include <cmath>
using namespace std;

int N, M;
int A[20][20];
int x, y;
int K;
int commands[1000];
int diceState[6];
int temp[6];

int dx[] = { 0, 0, 0, -1, 1 };
int dy[] = { 0, 1, -1, 0, 0 };

void input();

void left() {
	diceState[3] = temp[0];
	diceState[1] = temp[1];
	diceState[0] = temp[2];
	diceState[5] = temp[3];
	diceState[4] = temp[4];
	diceState[2] = temp[5];
}

void right() {
	diceState[2] = temp[0];
	diceState[1] = temp[1];
	diceState[5] = temp[2];
	diceState[0] = temp[3];
	diceState[4] = temp[4];
	diceState[3] = temp[5];
}

void up() {
	diceState[1] = temp[0];
	diceState[5] = temp[1];
	diceState[2] = temp[2];
	diceState[3] = temp[3];
	diceState[0] = temp[4];
	diceState[4] = temp[5];
}

void down() {
	diceState[4] = temp[0];
	diceState[0] = temp[1];
	diceState[2] = temp[2];
	diceState[3] = temp[3];
	diceState[5] = temp[4];
	diceState[1] = temp[5];
}

int main() {

	input();

	for (int i = 0; i < K; ++i) {
		int cmd = commands[i];

		int n_x = x + dx[cmd];
		int n_y = y + dy[cmd];

		if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= M) continue;

		x = n_x;
		y = n_y;

		for (int i = 0; i < 6; ++i)
			temp[i] = diceState[i];

		switch (cmd) {
		case 1:
			right();
			break;
		case 2:
			left();
			break;
		case 3:
			up();
			break;
		case 4:
			down();
			break;
		}

		if (A[x][y] == 0) {
			A[x][y] = diceState[5];
		}
		else {
			diceState[5] = A[x][y];
			A[x][y] = 0;
		}

		cout << diceState[0] << endl;
	}



	return 0;
}

void input() {
	cin >> N >> M >> x >> y >> K;
	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < M; ++y) {
			cin >> A[x][y];
		}
	}

	for (int i = 0; i < K; ++i)
		cin >> commands[i];
}
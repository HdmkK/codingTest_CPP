#include <iostream>
#include <vector>
#include <string>
using namespace std;


int N;
vector<string> board;

void getHeadXY(int& headX, int& headY) {
	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			if (board[x][y] == '*') {
				headX = x;
				headY = y;
				return;
			}
		}
	}
}

int getLeftArmLength(int heartX, int heartY) {

	int c_x = heartX;
	int c_y = heartY;
	int sum = 0;

	while (true) {
		c_y = c_y - 1;

		if (c_y < 0) break;
		if (board[c_x][c_y] == '_') break;

		sum++;
	}

	return sum;
}

int getRightArmLength(int heartX, int heartY) {

	int c_x = heartX;
	int c_y = heartY;
	int sum = 0;

	while (true) {
		c_y = c_y + 1;

		if (c_y >= N) break;
		if (board[c_x][c_y] == '_') break;

		sum++;
	}

	return sum;
}

int getWaistLengthAndBase(int heartX, int heartY
	, int& waistBaseX, int& waistBaseY) {

	int c_x = heartX;
	int c_y = heartY;
	int sum = 0;

	while (true) {
		c_x = c_x + 1;

		if (c_x >= N) break;
		if (board[c_x][c_y] == '_') break;

		sum++;
		waistBaseX = c_x;
		waistBaseY = c_y;
	}

	return sum;
}

int getLeftReg(int waistBaseX, int waistBaseY) {
	int c_x = waistBaseX;
	int c_y = waistBaseY - 1;
	int sum = 0;

	while (true) {
		c_x = c_x + 1;

		if (c_x >= N) break;
		if (board[c_x][c_y] == '_') break;

		sum++;
	}

	return sum;
}

int getRightReg(int waistBaseX, int waistBaseY) {
	int c_x = waistBaseX;
	int c_y = waistBaseY + 1;
	int sum = 0;

	while (true) {
		c_x = c_x + 1;

		if (c_x >= N) break;
		if (board[c_x][c_y] == '_') break;

		sum++;
	}

	return sum;
}
int main() {

	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; ++i) {
		string input;
		getline(cin, input);
		board.push_back(input);
	}

	//머리 찾기
	int headX, headY;
	getHeadXY(headX, headY);
	int heartX = headX + 1;
	int heartY = headY;

	//왼쪽팔 길이
	int leftArm = 0;
	leftArm = getLeftArmLength(heartX, heartY);

	//오른쪽팔 길이
	int rightArm = 0;
	rightArm = getRightArmLength(heartX, heartY);

	//허리 길이
	int waist = 0;
	int waistBaseX, waistBaseY;
	waist = getWaistLengthAndBase(heartX, heartY, waistBaseX, waistBaseY);

	//왼쪽 다리
	int leftLeg = 0;
	leftLeg = getLeftReg(waistBaseX, waistBaseY);

	//오른쪽 다리
	int rightLeg = 0;
	rightLeg = getRightReg(waistBaseX, waistBaseY);

	cout << heartX + 1 << " " << heartY + 1 << endl;
	cout << leftArm << " " << rightArm << " " << waist << " " << leftLeg << " " << rightLeg << endl;
	return 0;
}
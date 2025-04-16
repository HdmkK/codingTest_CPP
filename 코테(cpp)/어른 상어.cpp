#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
using namespace std;

int N, M, K; // N x N 판, 상어 M마리, K번 이동하면 냄새 사라짐.
vector<vector<tuple<int, int>>> grid; // 한요소 -> <어떤 shark, 냄새 count)
vector<unordered_map<int, vector<int>>> table; //각 상어의 현재 방향에 따른 방향 우선순위
vector<tuple<int, int>> sharkXY; // 상어(x좌표, y좌표)
vector<int> sharkDirection;
unordered_set<int> outShark; //밖으로 나가버린 상어
int sharkNum = M;
int seconds = 0;
int dx[] = { -99, -1, 1, 0, 0 };
int dy[] = { -99, 0, 0, -1, 1 };

void input();
void print();
void printSmell();
void renewSmell(); //냄새들을 갱신
void moveSharks(); //상어들을 이동시킨다.
void markingSmell();//상어들이 현재 위치에 냄새를 남긴다.
void checkCollision();//상어끼리 충돌 확인



int main() {

	input();

	markingSmell();
	//cout << "상어 개수 : " << sharkNum << endl;
	//cout << "초 : " << seconds << endl;
	//print();
	while (sharkNum > 1 && seconds <= 1000) {



		moveSharks();
		checkCollision();
		renewSmell();
		markingSmell();
		//print();
		//printSmell();

		seconds++;
	}

	if (seconds > 1000) cout << -1 << endl;
	else cout << seconds << endl;
	return 0;
}


void printSmell() {
	cout << "==================================" << endl;
	cout << "남은 상어 : " << sharkNum << endl;
	for (int shark = 1; shark <= M; ++shark) {
		auto& [x, y] = sharkXY[shark];
		cout << "상어" << shark << "(" << x << ", " << y << ")" << endl;
	}

	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			auto& [shark, cnt] = grid[x][y];
			cout << "(" << shark << ", " << cnt << ") | ";
		}
		cout << endl;
	}
}

void renewSmell() {
	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			auto& [shark, cnt] = grid[x][y];

			if (shark != -1 && --cnt == 0) {
				shark = -1;
				cnt = -1;
			}
		}
	}
}


void checkCollision() {

	vector<vector<int>> mem(N, vector<int>(N, 0));

	//높은 숫자 상어부터 충돌 여부 표시
	for (int shark = M; shark >= 1; --shark) {

		if (outShark.count(shark) > 0) continue;

		auto& [c_x, c_y] = sharkXY[shark];

		if (mem[c_x][c_y] > 0) {//나보다 우선순위가 낮은 상어가 이미 그자리에..
			sharkNum--;
			outShark.insert(mem[c_x][c_y]);
		}

		mem[c_x][c_y] = shark;
	}
}

void moveSharks() {
	//각 상어들어 대해서
	for (int shark = 1; shark <= M; ++shark) {

		if (outShark.count(shark) > 0) continue;

		auto& [c_x, c_y] = sharkXY[shark];
		bool flag = false;

		//먼저 빈칸에 대해서 탐색
		for (int i : table[shark][sharkDirection[shark]]) {
			int n_x = c_x + dx[i];
			int n_y = c_y + dy[i];

			//범위밖
			//자신 혹은 다른 상어 냄새
			if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= N)continue;
			if (get<0>(grid[n_x][n_y]) != -1) continue;

			//냄새X이므로 이동하고 현재방향도 갱신
			sharkXY[shark] = { n_x, n_y };
			sharkDirection[shark] = i;
			flag = true;
			break;
		}


		if (flag) continue; //이동했으니 다음 상어


		//못찾았다면 이번엔 자신의 냄새칸에 대해서 탐색
		for (int i : table[shark][sharkDirection[shark]]) {
			int n_x = c_x + dx[i];
			int n_y = c_y + dy[i];

			//범위밖
			//자신 혹은 다른 상어 냄새
			if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= N)continue;
			if (get<0>(grid[n_x][n_y]) != shark) continue;

			//빈공간이므로 이동하고 현재방향도 갱신
			sharkXY[shark] = { n_x, n_y };
			sharkDirection[shark] = i;

			//자기 냄새칸 cnt 초기화

			break;
		}


	}
}

void markingSmell() {
	//각 상어들에 대해서, 현재 위치에 냄새를 남긴다.
	for (int shark = 1; shark <= M; ++shark) {

		if (outShark.count(shark) > 0) continue;

		auto& [c_x, c_y] = sharkXY[shark];
		grid[c_x][c_y] = { shark, K };
	}
}


void print() {

	vector<vector<int>> A(N, vector<int>(N, 0));

	//상어 좌표 및 방향
	for (int shark = M; shark >= 1; --shark) {
		//cout << "상어[" << shark << "]" << endl;
		//cout << "좌표 : " << get<0>(sharkXY[shark]) << ", " << get<1>(sharkXY[shark]) << endl;
		//cout << "방향 : " << sharkDirection[shark] << endl;
		//cout << "우선순위" << endl;

		//for (int d = 1; d <= 4; ++d) {
		//	for (int i = 0; i < 4; ++i)
		//		cout << table[shark][d][i] << " ";
		//	cout << endl;
		//}

		if (outShark.count(shark) > 0) continue;

		auto& [x, y] = sharkXY[shark];
		A[x][y] = shark;
	}

	cout << "===========================" << endl;
	cout << "남은 상어 : " << sharkNum << endl;
	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			cout << A[x][y] << " ";
		}
		cout << endl;
	}


}

void input() {
	cin >> N >> M >> K;
	grid.resize(N, vector<tuple<int, int>>(N, { -1, -1 }));//-1이면 빈공간
	table.resize(M + 1);
	sharkXY.resize(M + 1);
	sharkDirection.resize(M + 1);
	sharkNum = M;


	//맵 + 상어 좌표 입력
	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			int input;
			cin >> input;
			if (input > 0) {//상어를 만났다면
				sharkXY[input] = { x, y };
			}
		}
	}

	//상어 방향 입력
	for (int shark = 1; shark <= M; ++shark) {
		cin >> sharkDirection[shark];
	}


	//상어마다 우선순위 입력받기
	for (int shark = 1; shark <= M; ++shark) {
		for (int i = 1; i <= 4; ++i) {
			for (int k = 1; k <= 4; ++k) {
				int input;
				cin >> input;
				table[shark][i].push_back(input);
			}
		}
	}
}
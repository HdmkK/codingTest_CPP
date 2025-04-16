#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
using namespace std;

int N, M, K; // N x N ��, ��� M����, K�� �̵��ϸ� ���� �����.
vector<vector<tuple<int, int>>> grid; // �ѿ�� -> <� shark, ���� count)
vector<unordered_map<int, vector<int>>> table; //�� ����� ���� ���⿡ ���� ���� �켱����
vector<tuple<int, int>> sharkXY; // ���(x��ǥ, y��ǥ)
vector<int> sharkDirection;
unordered_set<int> outShark; //������ �������� ���
int sharkNum = M;
int seconds = 0;
int dx[] = { -99, -1, 1, 0, 0 };
int dy[] = { -99, 0, 0, -1, 1 };

void input();
void print();
void printSmell();
void renewSmell(); //�������� ����
void moveSharks(); //������ �̵���Ų��.
void markingSmell();//������ ���� ��ġ�� ������ �����.
void checkCollision();//���� �浹 Ȯ��



int main() {

	input();

	markingSmell();
	//cout << "��� ���� : " << sharkNum << endl;
	//cout << "�� : " << seconds << endl;
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
	cout << "���� ��� : " << sharkNum << endl;
	for (int shark = 1; shark <= M; ++shark) {
		auto& [x, y] = sharkXY[shark];
		cout << "���" << shark << "(" << x << ", " << y << ")" << endl;
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

	//���� ���� ������ �浹 ���� ǥ��
	for (int shark = M; shark >= 1; --shark) {

		if (outShark.count(shark) > 0) continue;

		auto& [c_x, c_y] = sharkXY[shark];

		if (mem[c_x][c_y] > 0) {//������ �켱������ ���� �� �̹� ���ڸ���..
			sharkNum--;
			outShark.insert(mem[c_x][c_y]);
		}

		mem[c_x][c_y] = shark;
	}
}

void moveSharks() {
	//�� ����� ���ؼ�
	for (int shark = 1; shark <= M; ++shark) {

		if (outShark.count(shark) > 0) continue;

		auto& [c_x, c_y] = sharkXY[shark];
		bool flag = false;

		//���� ��ĭ�� ���ؼ� Ž��
		for (int i : table[shark][sharkDirection[shark]]) {
			int n_x = c_x + dx[i];
			int n_y = c_y + dy[i];

			//������
			//�ڽ� Ȥ�� �ٸ� ��� ����
			if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= N)continue;
			if (get<0>(grid[n_x][n_y]) != -1) continue;

			//����X�̹Ƿ� �̵��ϰ� ������⵵ ����
			sharkXY[shark] = { n_x, n_y };
			sharkDirection[shark] = i;
			flag = true;
			break;
		}


		if (flag) continue; //�̵������� ���� ���


		//��ã�Ҵٸ� �̹��� �ڽ��� ����ĭ�� ���ؼ� Ž��
		for (int i : table[shark][sharkDirection[shark]]) {
			int n_x = c_x + dx[i];
			int n_y = c_y + dy[i];

			//������
			//�ڽ� Ȥ�� �ٸ� ��� ����
			if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= N)continue;
			if (get<0>(grid[n_x][n_y]) != shark) continue;

			//������̹Ƿ� �̵��ϰ� ������⵵ ����
			sharkXY[shark] = { n_x, n_y };
			sharkDirection[shark] = i;

			//�ڱ� ����ĭ cnt �ʱ�ȭ

			break;
		}


	}
}

void markingSmell() {
	//�� ���鿡 ���ؼ�, ���� ��ġ�� ������ �����.
	for (int shark = 1; shark <= M; ++shark) {

		if (outShark.count(shark) > 0) continue;

		auto& [c_x, c_y] = sharkXY[shark];
		grid[c_x][c_y] = { shark, K };
	}
}


void print() {

	vector<vector<int>> A(N, vector<int>(N, 0));

	//��� ��ǥ �� ����
	for (int shark = M; shark >= 1; --shark) {
		//cout << "���[" << shark << "]" << endl;
		//cout << "��ǥ : " << get<0>(sharkXY[shark]) << ", " << get<1>(sharkXY[shark]) << endl;
		//cout << "���� : " << sharkDirection[shark] << endl;
		//cout << "�켱����" << endl;

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
	cout << "���� ��� : " << sharkNum << endl;
	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			cout << A[x][y] << " ";
		}
		cout << endl;
	}


}

void input() {
	cin >> N >> M >> K;
	grid.resize(N, vector<tuple<int, int>>(N, { -1, -1 }));//-1�̸� �����
	table.resize(M + 1);
	sharkXY.resize(M + 1);
	sharkDirection.resize(M + 1);
	sharkNum = M;


	//�� + ��� ��ǥ �Է�
	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			int input;
			cin >> input;
			if (input > 0) {//�� �����ٸ�
				sharkXY[input] = { x, y };
			}
		}
	}

	//��� ���� �Է�
	for (int shark = 1; shark <= M; ++shark) {
		cin >> sharkDirection[shark];
	}


	//���� �켱���� �Է¹ޱ�
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
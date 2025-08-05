#include <iostream>
#include <unordered_map>
#include <unordered_set>;
using namespace std;

static int N;

int M[25][25]; // ���� ���� ���� �ε���
int S[25][25]; // ���� ���� ���� ����

unordered_map<string, int> M_INDEX;

int M_X[700];
int M_Y[700];

int parent[700];
int rankData[700];
unordered_set<int> enermy[625];

int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void init(int N, int mSoldier[25][25], char mMonarch[25][25][11])
{
	::N = N;

	int ticket = 1;
	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			S[x][y] = mSoldier[x][y];
			M[x][y] = ticket;
			M_X[ticket] = x;
			M_Y[ticket] = y;
			M_INDEX[mMonarch[x][y]] = ticket;
			ticket++;
		}
	}


	//���Ͽ� ���ε带 ���� �ʱ�ȭ
	int NN = ::N * ::N;
	for (int i = 1; i <= NN; ++i) {
		parent[i] = i;//��� �ڱ��ڽ��� �θ�
	}
}

void destroy()
{

}


static int find(int x) {
	if (parent[x] == x) return x;

	parent[x] = find(parent[x]);
	return parent[x];
}

static void unionSet(int x, int y) {
	int p_x = find(x);
	int p_y = find(y);

	if (p_x == p_y) return;

	if (rankData[p_x] > rankData[p_y]) {
		parent[p_y] = p_x;
		enermy[p_x].insert(enermy[p_y].begin(), enermy[p_y].end());
		enermy[p_y].clear();
	}
	else if (rankData[p_x] < rankData[p_y]) {
		parent[p_x] = p_y;
		enermy[p_y].insert(enermy[p_x].begin(), enermy[p_x].end());
		enermy[p_x].clear();
	}
	else if (rankData[p_x] == rankData[p_y]) {
		parent[p_y] = p_x;
		rankData[p_x] += 1;
		enermy[p_x].insert(enermy[p_y].begin(), enermy[p_y].end());
		enermy[p_y].clear();
	}
}

int ally(char mMonarchA[11], char mMonarchB[11])
{
	int a_idx = M_INDEX[mMonarchA];
	int b_idx = M_INDEX[mMonarchB];

	if (a_idx == b_idx || find(a_idx) == find(b_idx)) {
		cout << a_idx << ", " << b_idx << endl;
		cout << mMonarchA << "�� " << mMonarchB << "�� �̹� �����Դϴ�." << endl;
		return -1;
	};

	auto& enermies = enermy[find(a_idx)];
	for (int e : enermies) {
		if (find(e) == find(b_idx)) {
			cout << mMonarchA << "�� " << mMonarchB << "�� ��������̱� ������ ������ ���� �� �����ϴ�." << endl;
			return -2;
		}
	}

	unionSet(a_idx, b_idx);
	cout << mMonarchA << "�� " << mMonarchB << "�� ������ �ξ����ϴ�." << endl;
	return 1;
}


void changeMonarch(char mMonarchA[], char mMonarchB[], char mGeneral[]) {

	int a_idx = M_INDEX[mMonarchA];

	int b_idx = M_INDEX[mMonarchB];
	M_INDEX.erase(mMonarchB);
	M_INDEX[mGeneral] = b_idx;

	//�׷� ����
	if (find(b_idx) == b_idx) {//�ڱ� �ڽ��� �׷����̿��ٸ�
		
		int next_parent = 0;
		for (int i = 1; i <= ::N * ::N; ++i) {
			if (parent[i] == b_idx) {

				if (next_parent == 0) {
					next_parent = i;
					parent[next_parent] = next_parent;
					continue;
				}

				parent[i] = next_parent;
				enermy[next_parent].insert(enermy[b_idx].begin(), enermy[b_idx].end());
				enermy[b_idx].clear();
			}
		}

		parent[b_idx] = b_idx;
		rankData[b_idx] = 0;
		unionSet(a_idx, b_idx);


		//Ȥ�� a�� �������set�� b��Ұ� ���ԵǾ� �ִٸ�, ��� ��ü �׷����� �������� �߰�
		if (enermy[find(a_idx)].count(b_idx) > 0) {
			enermy[find(a_idx)].erase(b_idx);
			enermy[find(a_idx)].insert(next_parent);
		}
		
	}
	else {//���� �ڽ��� �׷��� �ƴ�
		for (int i = 1; i <= ::N * ::N; ++i) {
			if (parent[i] == b_idx)
				parent[i] = parent[b_idx];
		}

		parent[b_idx] = b_idx;
		rankData[b_idx] = 0;
		unionSet(a_idx, b_idx);
	}

}

int attack(char mMonarchA[11], char mMonarchB[11], char mGeneral[11])
{
	int a_idx = M_INDEX[mMonarchA];
	int b_idx = M_INDEX[mMonarchB];

	if (find(a_idx) == find(b_idx)) return -1;

	int a_x = M_X[a_idx];
	int a_y = M_Y[a_idx];

	int b_x = M_X[b_idx];
	int b_y = M_Y[b_idx];

	bool flag = false;
	int a_ally_s = 0;
	int b_ally_s = S[b_x][b_y];

	for (int i = 0; i < 8; ++i) {
		int n_x = b_x + dx[i];
		int n_y = b_y + dy[i];
		if (n_x < 0 || n_x >= ::N || n_y < 0 || n_y >= ::N) continue;

		if (find(M[n_x][n_y]) == find(a_idx)) {
			flag = true;
			int plus = S[n_x][n_y] / 2;
			a_ally_s += plus;
			S[n_x][n_y] -= plus;
		}
		else if (find(M[n_x][n_y]) == find(b_idx)) {
			int plus = S[n_x][n_y] / 2;
			b_ally_s += plus;
			S[n_x][n_y] -= plus;
		}
	}


	if (not flag) return -2;


	if (a_ally_s > b_ally_s) {
		//a�� b�� ������迡 �߰�
		//b�� a�� ������迡 �߰�
		enermy[find(a_idx)].insert(find(b_idx));
		enermy[find(b_idx)].insert(find(a_idx));

		//���� ��ü
		changeMonarch(mMonarchA, mMonarchB, mGeneral);

		S[b_x][b_y] -= a_ally_s - b_ally_s;

		cout << mMonarchA << "�� " << mMonarchB << "�� �����ϴµ� ����" << endl;
		return 1;
	}
	else if (a_ally_s <= b_ally_s) {
		//a�� b�� ������迡 �߰�
		//b�� a�� ������迡 �߰�
		enermy[find(a_idx)].insert(find(b_idx));
		enermy[find(b_idx)].insert(find(a_idx));
		
		S[b_x][b_y] -= b_ally_s - a_ally_s;
		cout << mMonarchA << "�� " << mMonarchB << "�� �� ���� ���� ����" << endl;
		return 0;
	}
}

int recruit(char mMonarch[11], int mNum, int mOption)
{
	return -1;
}

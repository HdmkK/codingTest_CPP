#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int N;
unordered_map<int, unordered_set<int>> friendMap;
vector<vector<int>> grid;
vector<int> order;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void input();
void print();
void setGrid();
int getSum();

int main() {

	input();
	setGrid();
	cout << getSum() << endl;
	return 0;
}

int getSum() {
	int sum = 0;
	int score[] = { 0, 1, 10, 100, 1000 };
	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {

			int tmp = 0;

			for (int i = 0; i < 4; ++i) {
				int n_x = x + dx[i];
				int n_y = y + dy[i];

				if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= N)continue;

				if (friendMap[grid[x][y]].count(grid[n_x][n_y]) > 0) tmp++;

			}

			sum += score[tmp];

		}
	}
	return sum;
}

void setGrid() {

	for (int me : order) {

		int t_x, t_y;
		int maxAffinityNum = -1, maxNoOwner = -1;

		for (int x = 0; x < N; ++x) {
			for (int y = 0; y < N; ++y) {

				if (grid[x][y] > 0) continue;

				int affinityNum = 0, noOwner = 0;
				for (int i = 0; i < 4; ++i) {
					int n_x = x + dx[i];
					int n_y = y + dy[i];

					if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= N)continue;

					if (grid[n_x][n_y] == 0) noOwner++;
					else if (friendMap[me].count(grid[n_x][n_y]) > 0)
						affinityNum++;
				}

				if (affinityNum > maxAffinityNum) {
					maxAffinityNum = affinityNum;
					maxNoOwner = noOwner;
					t_x = x;
					t_y = y;
					continue;
				}
				else if (affinityNum == maxAffinityNum) {
					if (noOwner > maxNoOwner) {
						maxAffinityNum = affinityNum;
						maxNoOwner = noOwner;
						t_x = x;
						t_y = y;
						continue;
					}
				}
			}
		}

		grid[t_x][t_y] = me;
	}
}

void input() {
	cin >> N;
	grid.assign(N, vector<int>(N, 0));
	for (int i = 0; i < N * N; ++i) {
		int student;
		cin >> student;
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		friendMap[student] = { a, b, c, d };
		order.push_back(student);
	}
}

void print() {
	for (int student : order) {
		cout << student << ", ";
		for (int affinity : friendMap[student])
			cout << affinity << " ";
		cout << endl;
	}
}
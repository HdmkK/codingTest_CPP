#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <unordered_set>
#include <queue>
using namespace std;

void input();
void print();
int findCostumer();
int bringCostumer(int who);



int N, M, fuel;
vector<vector<int>> grid;
int taxi_x, taxi_y;
unordered_map<int, tuple<int, int>> destination;
unordered_set<int> endCostumer;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main() {

	input();

	while (fuel > 0 && endCostumer.size() < M) {

		int who = findCostumer();
		if (who == -1) break;


		int use = bringCostumer(who);
		if (use == -1) break;

		fuel += 2 * use;
	}

	if (endCostumer.size() == M)
		cout << fuel << endl;
	else
		cout << -1 << endl;
	return 0;
}

int bringCostumer(int who) {

	auto& [d_x, d_y] = destination[who];

	queue<tuple<int, int, int>> q;
	q.push({ taxi_x, taxi_y, 0 });
	vector<vector<bool>> visited(N + 2, vector<bool>(N + 2, false));
	visited[taxi_x][taxi_y] = true;


	while (!q.empty()) {

		auto [c_x, c_y, d] = q.front();
		q.pop();

		if (fuel - d < 0) return -1;

		if (c_x == d_x && c_y == d_y) {
			fuel -= d;
			taxi_x = c_x;
			taxi_y = c_y;
			endCostumer.insert(who);
			return d;
		}



		for (int i = 0; i < 4; ++i) {
			int n_x = c_x + dx[i];
			int n_y = c_y + dy[i];

			if (grid[n_x][n_y] == -1) continue;
			if (visited[n_x][n_y]) continue;

			q.push({ n_x, n_y, d + 1 });
			visited[n_x][n_y] = true;
		}

	}

	return -1;
}

int findCostumer() {

	queue<tuple<int, int, int>> q;
	q.push({ taxi_x, taxi_y, 0 });
	vector<vector<bool>> visited(N + 2, vector<bool>(N + 2, false));
	visited[taxi_x][taxi_y] = true;

	int who = 0;
	int who_x = N + 2, who_y = N + 2;
	int min_d = -1;

	while (!q.empty()) {

		auto [c_x, c_y, d] = q.front();
		q.pop();


		//if (min_d != -1 && d > min_d) {
		//	fuel -= min_d;
		//	taxi_x = who_x;
		//	taxi_y = who_y;
		//	grid[taxi_x][taxi_y] = 0;
		//	return who;
		//}

		if (min_d != -1 && d > min_d) break;

		if (grid[c_x][c_y] > 0) {


			if (min_d == -1)
				min_d = d;

			if (c_x < who_x) {
				who = grid[c_x][c_y];
				who_x = c_x;
				who_y = c_y;
			}
			else if (c_x == who_x && c_y < who_y) {
				who = grid[c_x][c_y];
				who_x = c_x;
				who_y = c_y;
			}
		}

		if (fuel - d < 0) {
			return -1;
		}


		for (int i = 0; i < 4; ++i) {
			int n_x = c_x + dx[i];
			int n_y = c_y + dy[i];

			if (grid[n_x][n_y] == -1) continue;
			if (visited[n_x][n_y]) continue;

			q.push({ n_x, n_y, d + 1 });
			visited[n_x][n_y] = true;
		}

	}

	if (min_d == -1) return -1;

	fuel -= min_d;
	taxi_x = who_x;
	taxi_y = who_y;
	grid[taxi_x][taxi_y] = 0;
	return who;
}

void print() {

	for (int x = 0; x <= N + 1; ++x) {
		for (int y = 0; y <= N + 1; ++y) {
			cout << grid[x][y] << " ";
		}
		cout << endl;
	}


	for (int i = 1; i <= M; ++i) {
		auto& [x, y] = destination[i];
		cout << x << ", " << y << endl;
	}
}

void input() {
	cin >> N >> M >> fuel;
	grid.assign(N + 2, vector<int>(N + 2, 0));
	//visited.assign(N + 2, vector<bool>(N + 2, false));
	for (int i = 0; i <= N + 1; ++i) {
		for (int j = 0; j <= N + 1; ++j) {

			if (i == 0 || i == N + 1 || j == 0 || j == N + 1) {
				grid[i][j] = -1;
				continue;
			}

			int input;
			cin >> input;

			if (input == 1) grid[i][j] = -1;
		}
	}

	cin >> taxi_x >> taxi_y;

	for (int i = 1; i <= M; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		grid[a][b] = i;
		destination[i] = { c, d };
	}

}
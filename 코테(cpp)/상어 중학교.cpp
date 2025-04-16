#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <unordered_set>
#include <queue>
using namespace std;

void input();
void print();
int findBlockGroup();
void gravity();
void rotate270();


int N, M;
int score = 0;

vector<vector<int>> grid;
vector<vector<bool>> visited;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main() {

	input();
	int i = 1;
	while (true) {

		visited.assign(N, vector<bool>(N, false));

		int ret = findBlockGroup();
		if (ret == -1)break;

		gravity();
		rotate270();
		gravity();


	}

	cout << score << endl;
	return 0;
}

void rotate270() {
	auto tmp = grid;


	for (int y = N - 1; y >= 0; --y) {
		for (int x = 0; x < N; ++x) {
			grid[N - 1 - y][x] = tmp[x][y];
		}
	}
}


void gravity() {

	for (int x = N - 1; x >= 0; --x) {
		for (int y = 0; y < N; ++y) {

			if (grid[x][y] == -1) continue;

			int c_x = x;
			while (c_x + 1 < N && grid[c_x + 1][y] == 9) {
				grid[c_x + 1][y] = grid[c_x][y];
				grid[c_x][y] = 9;
				c_x++;
			}
		}
	}
}

void deleteBlockGroup(int s_x, int s_y) {

	int stdColor = grid[s_x][s_y];
	int B = 0;
	queue<tuple<int, int>> q;
	vector<vector<bool>> local_visited(N, vector<bool>(N, false));
	q.push({ s_x, s_y });
	local_visited[s_x][s_y] = true;

	while (!q.empty()) {

		auto [c_x, c_y] = q.front();
		q.pop();

		grid[c_x][c_y] = 9;
		B++;

		for (int i = 0; i < 4; ++i) {
			int n_x = c_x + dx[i];
			int n_y = c_y + dy[i];

			if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= N) continue;
			if (local_visited[n_x][n_y]) continue;

			if (grid[n_x][n_y] == stdColor || grid[n_x][n_y] == 0) {
				q.push({ n_x, n_y });
				local_visited[n_x][n_y] = true;
			}
		}
	}

	score += B * B;
}


void returnVisitOfRainbow(int s_x, int s_y) {
	int stdColor = grid[s_x][s_y];

	queue<tuple<int, int>> q;
	vector<vector<bool>> local_visited(N, vector<bool>(N, false));
	q.push({ s_x, s_y });
	local_visited[s_x][s_y] = true;

	while (!q.empty()) {

		auto [c_x, c_y] = q.front();
		q.pop();

		if (grid[c_x][c_y] == 0) visited[c_x][c_y] = false;


		for (int i = 0; i < 4; ++i) {
			int n_x = c_x + dx[i];
			int n_y = c_y + dy[i];

			if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= N) continue;
			if (local_visited[n_x][n_y]) continue;

			if (grid[n_x][n_y] == stdColor || grid[n_x][n_y] == 0) {
				q.push({ n_x, n_y });
				local_visited[n_x][n_y] = true;
			}
		}
	}

}

//s_x, s_y : 탐색 시작 좌표
//std_x, std_y : 그룹의 기준 블록 좌표(반환)
//->그룹 크기 반환
int BFS(int s_x, int s_y, int& std_x, int& std_y, int& rainbowBlockNum) {

	int stdColor = grid[s_x][s_y];
	int size = 0;
	std_x = N;
	std_y = N;
	rainbowBlockNum = 0;

	queue<tuple<int, int>> q;
	q.push({ s_x, s_y });
	visited[s_x][s_y] = true;

	while (!q.empty()) {

		auto [c_x, c_y] = q.front();
		q.pop();

		size++;

		//무지개 블록이라면
		if (grid[c_x][c_y] == 0) rainbowBlockNum++;

		//기준블록좌표갱신
		if (grid[c_x][c_y] != 9 && grid[c_x][c_y] != 0) {
			if (c_x < std_x) {
				std_x = c_x;
				std_y = c_y;
			}
			else if (c_x == std_x && c_y < std_y) {
				std_x = c_x;
				std_y = c_y;
			}
		}

		for (int i = 0; i < 4; ++i) {
			int n_x = c_x + dx[i];
			int n_y = c_y + dy[i];

			if (n_x < 0 || n_x >= N || n_y < 0 || n_y >= N) continue;
			if (visited[n_x][n_y]) continue;

			if (grid[n_x][n_y] == stdColor || grid[n_x][n_y] == 0) {
				q.push({ n_x, n_y });
				visited[n_x][n_y] = true;
			}
		}
	}

	returnVisitOfRainbow(s_x, s_y);
	return size;
}

int findBlockGroup() {

	int maxSize = 0;
	int c_std_x = -1, c_std_y = -1;
	int c_rainbowBlockNum = 0;
	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			if (grid[x][y] >= 1 && grid[x][y] <= M && !visited[x][y]) {
				//일반 블록이므로 탐색

				int std_x, std_y, rainbowBlockNum, size;
				size = BFS(x, y, std_x, std_y, rainbowBlockNum);

				/*cout << "크기 : " << size << ", ";
				cout << "좌표 : (" << std_x << ", " << std_y << ") , ";
				cout << "무지개 : " << rainbowBlockNum << endl << endl;*/
				if (size == 1) continue;//크기가 1이면 블록 그룹 탈락

				if (maxSize < size) {
					maxSize = size;
					c_std_x = std_x;
					c_std_y = std_y;
					c_rainbowBlockNum = rainbowBlockNum;
				}
				else if (maxSize == size && c_rainbowBlockNum < rainbowBlockNum) {
					maxSize = size;
					c_std_x = std_x;
					c_std_y = std_y;
					c_rainbowBlockNum = rainbowBlockNum;
				}
				else if (maxSize == size && c_rainbowBlockNum == rainbowBlockNum && c_std_x < std_x) {
					maxSize = size;
					c_std_x = std_x;
					c_std_y = std_y;
					c_rainbowBlockNum = rainbowBlockNum;
				}
				else if (maxSize == size && c_rainbowBlockNum == rainbowBlockNum && c_std_x == std_x && c_std_y < std_y) {
					maxSize = size;
					c_std_x = std_x;
					c_std_y = std_y;
					c_rainbowBlockNum = rainbowBlockNum;
				}

			}
		}
	}

	//블록 그룹 못찾음
	if (maxSize == 0) return -1;

	deleteBlockGroup(c_std_x, c_std_y);
	return maxSize;
}



void print() {

	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			cout << grid[x][y] << " ";
		}
		cout << endl;
	}
}

void input() {
	cin >> N >> M;
	grid.assign(N, vector<int>(N));
	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			cin >> grid[x][y];
		}
	}
}
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>;
using namespace std;

int N;
int answer = 0;
vector<bool> row;
unordered_set<int> diag1;
unordered_set<int> diag2;

void dfs(int i) {
	if (i == N) {
		answer++;
		return;
	}

	for (int j = 0; j < N; ++j) {
		if (row[j]) continue;
		if (diag1.count(i - j) > 0) continue;
		if (diag2.count(i + j) > 0) continue;

		row[j] = true;
		diag1.insert(i - j);
		diag2.insert(i + j);
		dfs(i + 1);

		diag1.erase(i - j);
		diag2.erase(i + j);
		row[j] = false;
	}
}

int main() {

	cin >> N;
	row.assign(N, false);
	dfs(0);
	cout << answer << endl;
	return 0;
}



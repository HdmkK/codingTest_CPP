#include <iostream>

using namespace std;

int N, M;
int S[20][20];
bool mem[20];
int alist[10];
int blist[10];
int answer = static_cast<int>(1e9);

int calc() {

	int aIdx = 0, bIdx = 0;
	int aSum = 0, bSum = 0;

	for (int i = 0; i < N; ++i) {
		if (mem[i])
			alist[aIdx++] = i;
		else
			blist[bIdx++] = i;
	}

	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < M; ++j) {
			aSum += S[alist[i]][alist[j]];
			bSum += S[blist[i]][blist[j]];
		}
	}

	return abs(aSum - bSum);

}

void dfs(int start, int cnt) {

	if (cnt == M) {
		int ret = calc();
		answer = min(answer, ret);
		return;
	}

	for (int i = start; i < N; ++i) {
		mem[i] = true;
		dfs(i + 1, cnt + 1);
		mem[i] = false;
	}
}

int main() {

	cin >> N;
	M = N / 2;
	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			cin >> S[x][y];
		}
	}

	fill(mem, mem + 20, false);

	dfs(0, 0);
	cout << answer << endl;
	return 0;
}
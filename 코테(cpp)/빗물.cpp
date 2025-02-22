#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;



void input();
bool compare(const tuple<int, int>& a, const tuple<int, int>& b);

int H, W;
vector<int> A;
vector<tuple<int, int>> mem;

int main() {

	int answer = 0;

	input();

	sort(mem.begin(), mem.end(), compare);

	auto [top_i, top_h] = mem[0];
	int left_i = 0, left_h = A[0];
	int right_i = W - 1, right_h = A[W - 1];

	while (left_i < top_i) {
		left_h = max(left_h, A[left_i]);
		answer += left_h - A[left_i];
		left_i++;
	}

	while (right_i > top_i) {
		right_h = max(right_h, A[right_i]);
		answer += right_h - A[right_i];
		right_i--;
	}

	cout << answer << endl;
	return 0;
}

bool compare(const tuple<int, int>& a, const tuple<int, int>& b) {
	return get<1>(a) > get<1>(b);
}


void input() {
	cin >> H >> W;
	for (int i = 0; i < W; ++i) {
		int input;
		cin >> input;
		A.push_back(input);
		mem.push_back({ i, input });
	}

}
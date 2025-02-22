#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

void input();

int N;
vector<tuple<int, int>> pillar;
vector<int> ground(1001, 0);


//기둥이 높은 순
bool compareA(const tuple<int, int>& a, const tuple<int, int>& b) {
	return get<1>(a) > get<1>(b);
}

//위치 기준 오름차순
bool compareB(const tuple<int, int>& a, const tuple<int, int>& b) {
	return get<0>(a) < get<0>(b);
}

int main() {

	input();

	sort(pillar.begin(), pillar.end(), compareA);
	auto [top, top_h] = pillar[0];

	sort(pillar.begin(), pillar.end(), compareB);

	auto [left, left_h] = pillar[0];
	auto [right, right_h] = pillar[N - 1];

	for (auto& [i, h] : pillar) {
		ground[i] = h;
	}

	int sum = 0;

	while (left < top) {

		if (ground[left] > left_h)
			left_h = ground[left];

		sum += left_h;
		left++;
	}

	while (right > top) {

		if (ground[right] > right_h)
			right_h = ground[right];

		sum += right_h;
		right--;
	}

	sum += top_h;

	cout << sum << endl;

	return 0;
}



void input() {
	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; ++i) {
		int a, b;
		cin >> a >> b;


		pillar.push_back({ a, b });
	}
}
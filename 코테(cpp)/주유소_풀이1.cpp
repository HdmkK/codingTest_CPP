#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

void input();

int N;
vector<long long> roads;
vector<long long> gasStation;

class Compare
{
public:
	bool operator() (const tuple<long, long>& a, const tuple<long, long>& b) {
		if (get<0>(a) == get<0>(b))
			return  get<1>(a) < get<1>(b);
		return get<0>(a) > get<0>(b);
	}
};

int main() {

	long long answer = 0;

	input();

	priority_queue<tuple<long long, long long>, vector<tuple<long long, long long>>, Compare > pq;

	long long dist_sum = 0;
	for (int i = N - 2; i >= 0; --i) {
		dist_sum += roads[i];
		pq.push({ gasStation[i], dist_sum });
	}

	long long pre_sum = 0;
	long long move_sum = 0;

	while (move_sum < dist_sum) {
		auto [oilPrice, dist] = pq.top();
		pq.pop();

		if (dist < pre_sum) continue;

		//cout << oilPrice << ", " << dist << endl;
		answer += oilPrice * (dist - pre_sum);
		move_sum += dist - pre_sum;
		pre_sum = dist;
	}

	cout << answer << endl;

	return 0;
}

void input() {
	cin >> N;
	for (int i = 0; i < N - 1; ++i) {
		long long input;
		cin >> input;
		roads.push_back(input);
	}

	for (int i = 0; i < N; ++i) {
		long long input;
		cin >> input;
		gasStation.push_back(input);
	}


}
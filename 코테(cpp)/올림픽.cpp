#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

int N, K;

class compare {
public:
	bool operator() (const tuple<int, int, int, int>& a, const tuple<int, int, int, int>& b) {
		int goldA = get<1>(a);
		int silverA = get<2>(a);
		int bronzeA = get<3>(a);

		int goldB = get<1>(b);
		int silverB = get<2>(b);
		int bronzeB = get<3>(b);

		if (goldA != goldB) return goldA < goldB;
		if (silverA != silverB) return silverA < silverB;
		return bronzeA < bronzeB;
	}
};

priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, compare> inputs;
int main() {

	cin >> N >> K;

	for (int i = 0; i < N; ++i) {
		int nationNum, gold, silver, bronze;
		cin >> nationNum >> gold >> silver >> bronze;
		inputs.push({ nationNum, gold, silver, bronze });
	}

	unordered_map<int, int> mem;
	
	int A = 1;
	int i = 0;

	int pre_gold = -1, pre_silver = -1, pre_bronze = -1;
	while (!inputs.empty()) {
		auto [nationNum, gold, silver, bronze] = inputs.top();
		inputs.pop();
		
		if (pre_gold == gold && pre_silver == silver && pre_bronze == bronze)
		{
			A++;
			mem[nationNum] = i;
		}
		else {
			i += A;
			A = 1;
			mem[nationNum] = i;
		}
		
		pre_gold = gold;
		pre_silver = silver;
		pre_bronze = bronze;
		
	}

	cout << mem[K] << endl;

	return 0;
}
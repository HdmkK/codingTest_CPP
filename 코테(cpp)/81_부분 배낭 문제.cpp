//아래 코드는 테스트 코드 입니다.
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

class Compare
{
public:
	bool operator() (const tuple<double, double>& a, const tuple<double, double>& b){
		return get<1>(a) < get<1>(b);
	}
};

double solution(vector<vector<double>> items, double weight_limit) {

	priority_queue<tuple<double, double>, vector<tuple<double, double>>, Compare> values;
	for (auto& lst : items) {
		double kg = lst[0];
		double price = lst[1];
		values.push({kg,  price / kg });
	}

	double max_value = 0;
	while(weight_limit > 0) {
		auto [kg, value] = values.top();
		values.pop();

		if (kg <= weight_limit) {
			weight_limit -= kg;
			max_value += (kg * value);
		}
		else {
			max_value += (weight_limit * value);
			weight_limit = 0;
		}
	}
	return max_value;
}

int main()
{
	cout << solution({ {10, 19}, {7, 10}, {6, 10} }, 15) << endl; //출력값 : 27.3333
	cout << solution({ {10, 60}, {20, 100}, {30, 120} }, 50) << endl; //출력값 : 240

	return 0;
}
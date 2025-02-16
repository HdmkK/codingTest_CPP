#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <unordered_map>
using namespace std;

int N, M;
vector<string> words;

class Compare
{
public:
	bool operator() (const tuple<string, int>& a, const tuple<string, int>& b) {
		auto [strA, cntA] = a;
		auto [strB, cntB] = b;

		if (cntA == cntB) {

			if (strA.length() == strB.length())
				return strA > strB;

			return strA.length() < strB.length();
		}

		return cntA < cntB;
	}

};
int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	cin >> N >> M;
	unordered_map<string, int> cnt;
	for (int i = 0; i < N; ++i) {
		string input;
		cin >> input;

		if (input.length() < M) continue;

		words.push_back(input);
		cnt[input]++;
	}

	priority_queue<tuple<string, int>, vector<tuple<string, int>>, Compare> pq;

	for (auto e : cnt) {
		pq.push({ e.first, e.second });
	}


	while (!pq.empty()) {
		auto [word, cnt] = pq.top();
		pq.pop();
		cout << word << '\n';
	}

	return 0;
}

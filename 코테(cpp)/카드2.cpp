#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N;

int main() {

	cin >> N;
	deque<int> q;
	for (int i = 1; i <= N; ++i)
		q.push_back(i);


	while (q.size() > 1) {
		q.pop_front();
		int tmp = q.front();
		q.pop_front();
		q.push_back(tmp);
	}

	cout << q[0] << endl;
	return 0;
}
#include <iostream>
#include <queue>

using namespace std;

void print_queue(queue<int>& my_q) {
	for (int i = 0; i < my_q.size(); ++i) {
		int tmp = my_q.front();
		my_q.pop();
		my_q.push(tmp);
		cout << tmp << " ";
	}
	cout << endl;
}

int solution(int N, int K) {
	queue<int> round;

	//큐 초기화
	for (int n = 1; n <= N; n++) {
		round.push(n);
	}

	//큐에 요소가 하나만 남을 때까지
	while (round.size() > 1) {
		//print_queue(round);
		int i = 1;
		while (i++ < K) {
			int num = round.front();
			round.pop();
			round.push(num);
		}

		round.pop();
	}
	return round.front();
}

int main() {

	int N = 5;
	int K = 3;
	cout << solution(N, K) << endl;
	return 0;
}
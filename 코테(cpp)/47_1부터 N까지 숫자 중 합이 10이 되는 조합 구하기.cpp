/***********피드백*********************/
// 재귀함수에서 base 순서 조심(base순서에 따라 결과가 달라질 수 있음(sum을 계산해서 검사해야하는데 안하고 back한다든지..)
// 부분집합 

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> answer;
int N = 7;

void print_vector(const vector<int>& list) {

	cout << "[";
	for (auto v : list) {
		cout << v << ", ";
	}
	cout << "]" << endl;
}

int get_sum(const vector<int>& cur) {
	int sum = 0;
	for (int value : cur) {
		sum += value;
	}
	return sum;
}

void DFS(int start, vector<int>& cur) {

	int sum = get_sum(cur);
	print_vector(cur);
	if (sum == 10) {
		answer.push_back(cur);
		return;
	}
	else if (sum > 10) {
		return;
	}

	//반복문 형태 중요
	for (int i = start; i <= N; ++i) {
		cur.push_back(i);
		DFS(i + 1, cur);
		cur.pop_back();
	}
	
}

vector<vector<int>> solution(int N) {
	

	vector<int> mem;
	DFS(1, mem);
	return answer;
}

int main() {

	
	
	auto results = solution(N);
	for (auto r : results) {
		for (auto i : r) {
			cout << i << ", ";
		}
		cout << endl;
	}
	return 0;
}
#include <iostream>
#include <stack>
#include <string>

using namespace std;


string solution(int n) {

	int a;
	int remain;
	string answer = "";
	stack<int> st;

	while (n > 0) {
		remain = n % 2;

		st.push(remain);
		n /= 2;
	}


	//스택에서 정수를 꺼내서 문자열로 변환
	while (!st.empty()) {
		answer += to_string(st.top());
		st.pop();
	}

	return answer;
}

int main() {

	cout << solution(10) << endl;
	cout << solution(27) << endl;
	cout << solution(12345) << endl;


	return 0;
}


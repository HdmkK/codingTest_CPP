#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;


bool solution(string str) {

	stack<char> st;

	for (auto c : str) {

		if (c == ')') {
			if (!st.empty() && st.top() == '(') {
				st.pop();
				continue;
			}
		}
		st.push(c);
	}

	return st.empty();
}

int main() {

	string str1 = "(())()";
	string str2 = "((())()";
	cout << solution(str1) << endl;
	cout << solution(str2) << endl;


	return 0;
}


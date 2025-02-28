#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string str;

int main() {

	int answer;

	cin >> str;

	int N = str.length();
	int bCnt = count(str.begin(), str.end(), 'b');

	str += str.substr(0, bCnt - 1);

	//현재 윈도우에서 a개수
	int mem = 0;
	for (int i = 0; i < bCnt; ++i)
		if (str[i] == 'a') mem++;

	answer = mem;

	for (int i = 1; i < N; ++i) {
		if (str[i - 1] == 'a') mem--;
		if (str[i + bCnt - 1] == 'a')mem++;
		answer = min(answer, mem);
	}

	cout << answer << endl;

	return 0;
}



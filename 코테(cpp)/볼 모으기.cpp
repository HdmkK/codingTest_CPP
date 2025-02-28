#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main() {

	cin >> N;
	string str;
	cin >> str;

	int answer = 500000;
	int i, sum;


	//case1
	sum = 0;
	i = 0;

	while (str[i] == 'R') i++;
	for (; i < N; ++i)
		if (str[i] == 'R') sum++;

	answer = min(answer, sum);

	//case2
	sum = 0;
	i = N - 1;

	while (str[i] == 'B') i--;
	for (; i >= 0; --i)
		if (str[i] == 'B') sum++;

	answer = min(answer, sum);

	//case3
	sum = 0;
	i = N - 1;

	while (str[i] == 'R') i--;
	for (; i >= 0; --i)
		if (str[i] == 'R') sum++;

	answer = min(answer, sum);

	//case4
	sum = 0;
	i = 0;

	while (str[i] == 'B') i++;
	for (; i < N; ++i)
		if (str[i] == 'B') sum++;

	answer = min(answer, sum);

	cout << answer << endl;

	return 0;
}



//아래 코드는 테스트 코드 입니다.
#include <iterator>
#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(int amount) {

	vector<int> answer;

	while (amount > 0) {
		if (amount >= 100)
		{
			answer.push_back(100);
			amount -= 100;
		}
		else if (amount >= 50) {
			answer.push_back(50);
			amount -= 50;
		}	
		else if (amount >= 10) {
			answer.push_back(10);
			amount -= 10;
		}
		else {
			answer.push_back(1);
			amount -= 1;
		}
	}

	return answer;
}

void print(vector<int> vec)
{
	copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
	cout << endl;
}


int main()
{
	print(solution(123)); //출력값 : 100 10 10 1 1 1
	print(solution(350)); //출력값 : 100 100 100 50

	return 0;
}
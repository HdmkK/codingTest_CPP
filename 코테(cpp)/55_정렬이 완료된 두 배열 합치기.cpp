//아래 코드는 테스트 코드 입니다.
#include <iterator>
#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr1, vector<int> arr2) {
	vector<int> answer;

	int i = 0, j = 0;
	while (i < arr1.size() || j < arr2.size()) {
		
		if (j == arr2.size()) {
			answer.push_back(arr1[i++]);
			continue;
		}

		if (i == arr1.size()) {
			answer.push_back(arr2[j++]);
			continue;
		}

		if (arr1[i] < arr2[j])
			answer.push_back(arr1[i++]);
		else
			answer.push_back(arr2[j++]);
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
	print(solution({ 1, 3, 5 }, { 2, 4, 6 })); // 출력값 : 1 2 3 4 5 6
	print(solution({ 1, 2, 3 }, { 4, 5, 6 })); // 출력값 : 1 2 3 4 5 6
	print(solution({}, { 4, 10,11,12 })); // 출력값 : 1 2 3 4 5 6

	return 0;
}
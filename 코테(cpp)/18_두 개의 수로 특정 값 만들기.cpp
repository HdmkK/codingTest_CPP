#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool solution(vector<int> arr, int target) {

	unordered_map<int, int> mem;

	for (int num : arr) {
		mem.insert(make_pair(num, 0));
	}

	for (vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) {
		int b = target - *it;

		if (*it != b && mem.find(b) != mem.end()) {
			cout << *it << ", " << b << endl;
			return true;
		}
	}

	return false;
}

int main() {

	vector<int> arr = { 1,2,3,4,5 };
	int target = 6;
	/*vector<int> arr = { 2,3,5,9};
	int target = 10;*/
	cout << solution(arr, target) << endl;
	return 0;
}
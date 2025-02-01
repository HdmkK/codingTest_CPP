//�Ʒ� �ڵ�� �׽�Ʈ �ڵ� �Դϴ�.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<int>& dp) {
	for (int v : dp) {
		cout << v << " ";
	}
	cout << endl;
}
// ���� ���� �κ� ����(LIS)�� ���̸� ����ϴ� �Լ�
int solution(const vector<int> nums) {
	int N = nums.size();
	vector<int> dp(N, 0);
	dp[0] = 1;

	for (int i = 1; i < N; ++i) {
		int max_value = 0;
		for (int j = 0; j < i; ++j) {
			if (nums[j] < nums[i])
				max_value = max(max_value, dp[j]);
		}
		dp[i] = max_value + 1;
		//print(dp);
	}

	vector<int>::iterator it = max_element(dp.begin(), dp.end());
	return *it;
	
}

int main()
{
	cout << solution({ 1, 4, 2, 3, 1, 5, 7, 3 }) << endl; //��°� : 5
	cout << solution({ 3, 2, 1 }) << endl; //��°� : 1
	cout << solution({ 1, 4, 2, 3, 1, 5, 7, 3 }) << endl; // ��°�: 5
	cout << solution({ 3, 2, 1 }) << endl;               // ��°�: 1
	cout << solution({ 10, 20, 10, 30, 20, 50 }) << endl; // ��°�: 4
	cout << solution({ 3, 10, 2, 1, 20 }) << endl;       // ��°�: 3
	cout << solution({ 50, 3, 10, 7, 40, 80 }) << endl;  // ��°�: 4
	cout << solution({ 10, 9, 2, 5, 3, 7, 101, 18 }) << endl; // ��°�: 4
	cout << solution({ 1, 2, 3, 4, 5 }) << endl;         // ��°�: 5
	cout << solution({ 5, 4, 3, 2, 1 }) << endl;         // ��°�: 1
	cout << solution({ 1, 3, 2, 3, 4, 8, 7, 9, 10 }) << endl; // ��°�: 7
	cout << solution({ 1 }) << endl;                    // ��°�: 1
	//cout << solution({}) << endl;                     // ��°�: 0
	cout << solution({ 10, 20, 30, 10, 20, 30, 40 }) << endl; // ��°�: 4
	cout << solution({ 4, 10, 4, 3, 8, 9 }) << endl;     // ��°�: 3
	cout << solution({ 1, 2, 8, 6, 4, 5, 7, 10, 9 }) << endl; // ��°�: 6

	return 0;
}
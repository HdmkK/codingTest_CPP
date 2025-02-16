#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> coin;

int main() {

	cin >> n >> k;
	coin.push_back(0);
	for (int i = 0; i < n; ++i) {
		int input;
		cin >> input;
		coin.push_back(input);
	}

	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {

			//�̶��� ���� �ϳ��� �ذᰡ���ϹǷ� ������ �ּ� ���� ���� = 1
			if (coin[i] == j) {
				dp[i][j] = 1;
				continue;
			}

			//���� ������ �߰��ؼ� ����� �����Ƿ�, ���� ���������� ������� �ʴ� ���̽�(���� : i-1)
			// �� �ּҰ����� �״�� ������
			if (j - coin[i] < 0) {
				dp[i][j] = dp[i - 1][j];
				continue;
			}

			//�Ѵ� 0�̸� ���� k�� ���� ����� ���� = 0
			if (dp[i - 1][j] == 0 && dp[i][j - coin[i]] == 0) {
				dp[i][j] = 0;
			}
			//���� ���� "����"�� �������� ��, k�� ���� ���X -> "���� ����"�� �߰��ϱ� ��
			// �ּ� ���� �������� + 1(���� ������ �߰��Ͽ� k�� ����Ƿ�)
			else if (dp[i - 1][j] == 0) {
				dp[i][j] = dp[i][j - coin[i]] + 1;
			}
			//"���� ����"�� �߰��ؼ� k�� ���� ���X -> ���� ���� "����"�� ������ ���̽���
			//�ּ� ���� ������ �״�� ������
			else if (dp[i][j - coin[i]] == 0) {
				dp[i][j] = dp[i - 1][j];
			}
			//"���� ����"�� �߰��ؼ��� k�� ���� �� �ְ�,
			//���� ���� ������ �����ϰ� k�� ���� �� �����Ƿ�
			// �� �� �� ���� ���̽��� �����Ѵ�.
			else {
				dp[i][j] = min(dp[i - 1][j], dp[i][j - coin[i]] + 1);
			}
		}
	}

	if (dp[n][k] == 0)
		cout << -1 << endl;
	else
		cout << dp[n][k] << endl;


	return 0;
}
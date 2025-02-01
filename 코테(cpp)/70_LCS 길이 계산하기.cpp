//아래 코드는 테스트 코드 입니다.
#include <iostream>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
	int M = str1.length();
	int N = str2.length();

	//DP용 테이블
	vector<vector<int>> mem(M+1, vector<int>(N+1, 0));

	for (int i = 1; i <= M; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (str1[i-1] == str2[j-1])
				mem[i][j] = mem[i - 1][j - 1] + 1;
			else if (str1[i-1] != str2[j-1])
				mem[i][j] = max(mem[i - 1][j], mem[i][j - 1]);
			
		}
	}

	return mem[M][N];
}

int main()
{
	//cout << solution("ABCBDAB", "BDCAB") << endl; //출력값: 4
	//cout << solution("AGGTAB", "GXTXAYB") << endl; //출력값 :4
	cout << solution("ABCBDAB", "BDCAB") << endl;      // 출력값: 4
	cout << solution("AGGTAB", "GXTXAYB") << endl;     // 출력값: 4
	cout << solution("abcde", "ace") << endl;         // 출력값: 3
	cout << solution("abc", "abc") << endl;           // 출력값: 3
	cout << solution("abc", "def") << endl;           // 출력값: 0
	cout << solution("abcdefgh", "aebdfgh") << endl;  // 출력값: 6
	cout << solution("abcd", "dcba") << endl;         // 출력값: 1
	cout << solution("AGGTAB", "GXTXAYB") << endl;    // 출력값: 4
	cout << solution("aaaa", "aa") << endl;          // 출력값: 2
	cout << solution("abcdef", "") << endl;          // 출력값: 0
	cout << solution("", "abcdef") << endl;          // 출력값: 0
	cout << solution("", "") << endl;                // 출력값: 0
	cout << solution("abcde", "acebd") << endl;      // 출력값: 3
	return 0;
}
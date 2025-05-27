#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <limits>
using namespace std;

int N;
int TC;
int main() {

	cin >> TC;

	for (int testcase = 0; testcase < TC; ++testcase) {

		cin >> N;

		vector<int> A(N + 1, 0);
		vector<int> score(N + 1, 0);
		unordered_map<int, int> cnt;
		for (int i = 1; i <= N; ++i) {
			cin >> A[i];
			cnt[A[i]]++;
		}



		//1.  6명인 팀 탐색
		unordered_set<int> validTeam;
		for (auto& [team, n] : cnt) {
			if (n == 6) validTeam.insert(team);
		}


		//2. 점수 부여
		int ticket = 1;
		for (int i = 1; i <= N; ++i) {
			if (validTeam.count(A[i]) > 0) {
				score[i] = ticket++;
			}
		}


		//3. map에 저장
		unordered_map<int, vector<int>> mem;
		for (int i = 1; i <= N; ++i) {

			if (score[i] == 0) continue;

			mem[A[i]].push_back(score[i]);
		}

		int candidate = 0;
		int minScore = numeric_limits<int>::max();
		int fifthScore = 0;

		for (auto& [team, scores] : mem) {

			if (validTeam.count(team) == 0) continue;


			int score4 = 0;
			int cur_fifthScore = 0;
			for (int i = 0; i < 4; ++i) {
				score4 += scores[i];
			}
			cur_fifthScore = scores[4];


			if (minScore == score4) {
				if (fifthScore > cur_fifthScore) {
					fifthScore = cur_fifthScore;
					candidate = team;
				}
			}

			if (minScore > score4) {
				fifthScore = cur_fifthScore;
				minScore = score4;
				candidate = team;
			}

		}

		cout << candidate << endl;

	}

	return 0;
}
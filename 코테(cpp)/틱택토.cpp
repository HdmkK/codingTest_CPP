#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	while (s != "end") {

		vector<vector<char>> map(3, vector<char>(3));

		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				map[i][j] = s[3 * i + j];
			}
		}



		int Xcnt = 0;
		vector<int> Xrow(3, 0);
		vector<int> Xcol(3, 0);
		int Xdiag1 = 0, Xdiag2 = 0;
		int Xbingo = 0;

		int Ocnt = 0;
		vector<int> Orow(3, 0);
		vector<int> Ocol(3, 0);
		int Odiag1 = 0, Odiag2 = 0;
		int Obingo = 0;

		for (int x = 0; x < 3; ++x) {
			for (int y = 0; y < 3; ++y) {
				if (map[x][y] == 'O') {
					Ocnt++;
					Orow[x]++;
					Ocol[y]++;

					if (x == y) Odiag1++;
					if (x + y == 2) Odiag2++;

					if (Orow[x] == 3) Obingo++;
					if (Ocol[y] == 3) Obingo++;
					if (Odiag1 == 3) Obingo++;
					if (Odiag2 == 3) Obingo++;
				}
				else if (map[x][y] == 'X') {
					Xcnt++;
					Xrow[x]++;
					Xcol[y]++;

					if (x == y) Xdiag1++;
					if (x + y == 2) Xdiag2++;

					if (Xrow[x] == 3) Xbingo++;
					if (Xcol[y] == 3) Xbingo++;
					if (Xdiag1 == 3) Xbingo++;
					if (Xdiag2 == 3) Xbingo++;
				}
			}
		}

		//cout << Xbingo << ", " << Xcnt << ", " << Ocnt << endl;
		bool flag = false;
		if (Obingo > 0 && Xcnt == Ocnt && Xbingo == 0)
			flag = true;
		if (Xbingo > 0 && Xcnt == Ocnt + 1 && Obingo == 0)
			flag = true;
		if (Xbingo == 0 && Obingo == 0 && Xcnt == 5 && Ocnt == 4)
			flag = true;

		if (flag)
			cout << "valid\n";
		else
			cout << "invalid\n";



		cin >> s;
	}

	return 0;
}



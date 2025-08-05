#include <iostream>

using namespace std;

int H, M;

string H_STR[13] = {
	"",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine",
	"ten",
	"eleven",
	"twelve"
};

string M_STR[] = {
	"",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine",
	"ten",
	"eleven",
	"twelve",
	"thirteen",
	"fourteen",
	"fifteen",
	"sixteen",
	"seventeen",
	"eighteen",
	"nineteen"
};

string M10_STR[] = {
	"",
	"ten",
	"twenty",
	"thirty",
	"fourty",
	"fifty"
};


int main() {
	cin >> H;
	cin >> M;


	if (M == 0) {
		cout << H_STR[H] << " o' clock" << endl;
	}
	else if (M == 15) {
		cout << "quarter past " << H_STR[H] << endl;
	}
	else if (M == 30) {
		cout << "half past " << H_STR[H] << endl;
	}
	else if (M == 45) {
		cout << "quarter to " << H_STR[((H + 1 == 13) ? 1 : H + 1)] << endl;
	}
	else if (M % 10 == 0) {

		if (M >= 30) {
			M = (60 - M);
			cout << M10_STR[M / 10] << " minutes to " << H_STR[((H + 1 == 13) ? 1 : H + 1)] << endl;
		}

		cout << M10_STR[M / 10] << " minutes past " << H_STR[H] << endl;


	}
	else if (M >= 1 && M <= 19) {
		if (M == 1) {
			cout << M_STR[M] << " minute past " << H_STR[H] << endl;
		}
		else {
			cout << M_STR[M] << " minutes past " << H_STR[H] << endl;
		}
	}
	else if (M >= 21 && M <= 29) {

		int M_digit_10 = M / 10;
		int M_digit_1 = M % 10;

		cout << M10_STR[M_digit_10] << " " << M_STR[M_digit_1] << " minutes past " << H_STR[H] << endl;
	}
	else if (M >= 31 && M <= 39) {
		int M_digit_10 = (60 - M) / 10;
		int M_digit_1 = (60 - M) % 10;

		cout << M10_STR[M_digit_10] << " " << M_STR[M_digit_1] << " minutes to " << H_STR[((H + 1 == 13) ? 1 : H + 1)] << endl;
	}
	else {
		cout << M_STR[(60 - M)] << " minutes to " << H_STR[((H + 1 == 13) ? 1 : H + 1)] << endl;
	}

	return 0;
}
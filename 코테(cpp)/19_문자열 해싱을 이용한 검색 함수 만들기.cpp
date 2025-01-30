#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

long long polynomial_hash(const string& str) {
	const int p = 31;
	const long long m = 1000000007;
	long long hash_value = 0;

	for (char c : str) {
		if (hash_value == 0) {
			hash_value = c;
			continue;
		}
		hash_value = (hash_value + (c - 'a' + 1) * )
	}
}
int main() {
	
	return 0;
}
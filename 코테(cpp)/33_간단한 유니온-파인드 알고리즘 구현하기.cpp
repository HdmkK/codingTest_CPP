#include <iostream>
#include <vector>
#include <array>
using namespace std;

class UF
{
public:
	array<int, 1000> mem;
	array<int, 1000> rank;
public:


	//처음은 모든 노드가 루트노드
	void init(int k) {
		for (int i = 0; i < k; ++i) {
			mem[i] = i;
			rank[i] = 0;
		}
	}

	//집합 합치기(유니온 연산)
	void op_union(int x, int y) {
		int root_x = op_find(x);
		int root_y = op_find(y);

		
		if (isSameRoot(x, y))
			return;

		int root;
		int child;

		if (root_x > root_y) {
			root = root_x;
			child = root_y;
		}
		else if (root_x < root_y) {
			root = root_y;
			child = root_x;
		}
		else {
			//둘중 아무거나 루트해도 무방
			//다만 루트가 된 노드의 랭크를 +1
			root = root_x;
			rank[root]++;
		}

		mem[child] = root;
		
	}

	//루트 노드 찾기
	/*int op_find(int x) {
		int idx = x;
		
		while (idx != mem[idx]) {
			idx = mem[idx];
		}
		return idx;
	}*/

	int op_find(int x) {

		//루트 찾음
		if (x == mem[x])
			return x;

		mem[x] = op_find(mem[x]); // 모든 하위 노드가 루트 노드를 직접 가리키도록 -> 경로 압축

		return mem[x];
	}

	//동일 루트노드를 갖는지 확인
	int isSameRoot(int x, int y) {
		return op_find(x) == op_find(y);
	}
};

vector<bool> solution(int k, vector<vector<char>>& operations) {

	vector<bool> answer;
	UF uf;

	uf.init(k);

	for (auto op : operations) {
		char cmd = op[0];
		int x = op[1] - '0';
		int y = op[2] - '0';

		switch (cmd) {
		case 'u':
			uf.op_union(x, y);
			break;
		case 'f':
			answer.push_back(uf.isSameRoot(x, y));
			break;
		}
	}


	return answer;
}

int main() {

	int k = 4;
	/*vector<vector<char>> operations{
		{'u', '0', '1'},
		{'u', '1', '2'},
		{'f', '0', '2'}
	};*/

	vector<vector<char>> operations{
		{'u', '0', '1'},
		{'u', '2', '3'},
		{'f', '0', '1'},
		{'f', '0', '2'}
	};

	for (auto v : solution(k, operations)) {
		cout << v << " ";
	 }

	return 0;
}
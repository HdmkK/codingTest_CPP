#include <iostream>
#include <vector>
#include <string>

using namespace std;

string vectorToString(const vector<int>& nums) {
	string result = "";
	for (int num : nums) {
		result = result + to_string(num) + " ";
	}

	result.pop_back();
	return result;
}

void preorder(const vector<int>& nodes, vector<int>& cur, int i) {

	if (i >= nodes.size())
		return;
	
	int left_node = 2 * i + 1;
	int right_node = 2 * i + 2;

	cur.push_back(nodes[i]);

	preorder(nodes, cur, left_node);
	preorder(nodes, cur, right_node);
	

}

void inorder(const vector<int>& nodes, vector<int>& cur, int i) {

	if (i >= nodes.size())
		return;
	
		

	int left_node = 2 * i + 1;
	int right_node = 2 * i + 2;

	inorder(nodes, cur, left_node);
	cur.push_back(nodes[i]);
	inorder(nodes, cur, right_node);
}

void postorder(const vector<int>& nodes, vector<int>& cur, int i) {

	if (i >= nodes.size())
		return;

	int left_node = 2 * i + 1;
	int right_node = 2 * i + 2;

	postorder(nodes, cur, left_node);
	postorder(nodes, cur, right_node);
	cur.push_back(nodes[i]);
}

vector<string> solution(const vector<int>& nodes) {
	vector<string> answer;

	//전위
	vector<int> cur;
	preorder(nodes, cur, 0);
	answer.push_back(vectorToString(cur));

	//중위
	vector<int> cur1;
	inorder(nodes, cur1, 0);
	answer.push_back(vectorToString(cur1));

	//후위
	vector<int> cur2;
	postorder(nodes, cur2, 0);
	answer.push_back(vectorToString(cur2));

	return answer;
}
int main() {
	vector<int> nodes{ 1,2,3,4,5,6,7 };
	vector<string> results = solution(nodes);
	for (auto it = results.begin(); it != results.end(); ++it) {
		cout << *it << endl;
	}
	return 0;
}
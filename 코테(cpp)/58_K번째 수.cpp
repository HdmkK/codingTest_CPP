#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> subArray;
    for (auto command : commands) {
        int i = command[0];
        int j = command[1];
        int k = command[2];

        subArray.assign(array.begin() + (i - 1), array.begin() + j);
        sort(subArray.begin(), subArray.end());
        answer.push_back(subArray[k - 1]);
    }
    return answer;
}
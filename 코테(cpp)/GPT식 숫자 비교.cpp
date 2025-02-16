#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

bool compare(const string& a, const string& b) {
    stringstream ssa(a);
    stringstream ssb(b);

    int a_x = -1, a_y = -1;
    int b_x = -1, b_y = -1;

    string token;
    char delimiter = '.';
    getline(ssa, token, delimiter);
    a_x = stoi(token);
    if (getline(ssa, token, delimiter))
        a_y = stoi(token);

    getline(ssb, token, delimiter);
    b_x = stoi(token);
    if (getline(ssb, token, delimiter))
        b_y = stoi(token);

    //비교시작
    if (a_x != b_x)
        return a_x < b_x;

    return a_y < b_y;
}

int main(int argc, char** argv)
{
    int N;
    cin >> N;
    vector<string> inputs;
    for (int i = 0; i < N; ++i) {
        string tmp;
        cin >> tmp;

        inputs.push_back(tmp);
    }

    sort(inputs.begin(), inputs.end(), compare);

    for (string s : inputs)
        cout << s << endl;

    return 0;
}
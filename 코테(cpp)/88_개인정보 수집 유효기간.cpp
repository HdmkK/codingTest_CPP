#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <unordered_map>
using namespace std;

int c_y, c_m, c_d;
unordered_map<char, int> terms_dict;

void getTime(string& today, int& year, int& month, int& day) {
    stringstream ss(today);
    char delimiter = '.';
    string token;

    getline(ss, token, delimiter);
    year = stoi(token);
    getline(ss, token, delimiter);
    month = stoi(token);
    getline(ss, token, delimiter);
    day = stoi(token);
}

void initTermDict(vector<string>& terms) {

    for (string term : terms) {
        char a;
        int b;

        stringstream ss(term);
        char d = ' ';
        string token;
        getline(ss, token, d);
        a = token[0];
        getline(ss, token, d);
        b = stoi(token);
        terms_dict[a] = b;
    }

}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    getTime(today, c_y, c_m, c_d);
    initTermDict(terms);

    for (int i = 1; i <= privacies.size(); ++i) {

        string privacy = privacies[i - 1];
        stringstream ss(privacy);
        char delimiter = ' ';
        string token;
        string date;
        char term;

        getline(ss, token, delimiter);
        date = token;
        getline(ss, token, delimiter);
        term = token[0];

        int y, m, d;
        getTime(date, y, m, d);

        //약관의 날짜 -> y, m, d
        //약관 종류 -> term

        m -= 1;

        //만료시작날짜
        y += terms_dict[term] / 12;
        m += terms_dict[term] % 12;
        y += m / 12;
        m %= 12;
        m++;


        bool flag = false;
        if (c_y > y) flag = true;
        else if (c_y == y) {
            if (c_m > m) flag = true;
            else if (c_m == m) {
                if (c_d >= d) flag = true;
            }
        }


        if (flag)
            answer.push_back(i);
    }





    return answer;
}
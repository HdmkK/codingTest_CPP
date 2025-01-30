#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <iostream>

using namespace std;

class Action {
public:
    string uid;
    int action;

public:
    Action(string uid, int action)
        : uid(uid), action(action) {
    }
};

vector<string> split(string s, char delimiter) {
    istringstream iss(s);
    string buffer;

    vector<string> result;

    while (getline(iss, buffer, delimiter)) {
        result.push_back(buffer);
    }

    return result;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;

    vector<Action> action_tb; //[uid, 명령어]
    unordered_map<string, string> user_tb; //(유저id, 닉네임)
    unordered_map<string, int> action_idx{
        {"Enter", 0},
        {"Leave", 1}
    };

    for (int i = 0; i < record.size(); ++i) {
        vector<string> cmd_list = split(record[i], ' ');
        string action = cmd_list[0];
        string uid = cmd_list[1];
        string nickname = "";


        if (action != "Leave") {
            nickname = cmd_list[2];

            if (!user_tb.insert(make_pair(uid, nickname)).second)//조건문 거짓이면(새롭게 Enter)
                user_tb[uid] = nickname;//이미 user_tb에 있을 때(Change)
        }



        if (action != "Change")
            action_tb.push_back(Action(uid, action_idx[action]));


    }

    for (int i = 0; i < action_tb.size(); ++i) {
        string s;
        string cmd_string;
        s = "" + user_tb[action_tb[i].uid] + "님이 ";


        switch (action_tb[i].action) {
        case 0:
            cmd_string = "들어왔습니다.";
            break;
        case 1:
            cmd_string = "나갔습니다.";
            break;
        }

        s += cmd_string;
        answer.push_back(s);
    }

    return answer;
}


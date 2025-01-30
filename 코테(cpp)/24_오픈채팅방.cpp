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

    vector<Action> action_tb; //[uid, ��ɾ�]
    unordered_map<string, string> user_tb; //(����id, �г���)
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

            if (!user_tb.insert(make_pair(uid, nickname)).second)//���ǹ� �����̸�(���Ӱ� Enter)
                user_tb[uid] = nickname;//�̹� user_tb�� ���� ��(Change)
        }



        if (action != "Change")
            action_tb.push_back(Action(uid, action_idx[action]));


    }

    for (int i = 0; i < action_tb.size(); ++i) {
        string s;
        string cmd_string;
        s = "" + user_tb[action_tb[i].uid] + "���� ";


        switch (action_tb[i].action) {
        case 0:
            cmd_string = "���Խ��ϴ�.";
            break;
        case 1:
            cmd_string = "�������ϴ�.";
            break;
        }

        s += cmd_string;
        answer.push_back(s);
    }

    return answer;
}


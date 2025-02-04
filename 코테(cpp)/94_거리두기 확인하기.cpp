#include <string>
#include <vector>
#include <tuple>
#include <iostream>
using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void getPersonsXY(vector<string> place, vector<tuple<int, int>>& persons) {
    for (int x = 0; x < place.size(); ++x) {
        for (int y = 0; y < place[0].length(); ++y) {
            if (place[x][y] == 'P') {
                persons.push_back({ x, y });
            }
        }
    }
}

bool invalid(int x, int y, int N) {
    return (x < 0 || x >= N || y < 0 || y >= N);
}

int check(vector<string>& place, int room_number) {
    vector<tuple<int, int>> persons;
    getPersonsXY(place, persons);

    for (auto& [c_x, c_y] : persons) {
        for (int i = 0; i < 4; ++i) {
            int n_x = c_x + dx[i];
            int n_y = c_y + dy[i];

            if (invalid(n_x, n_y, 5)) continue;
            if (place[n_x][n_y] == 'X') continue;

            if (place[n_x][n_y] == 'P') {
                return 0;
            }

            for (int j = 0; j < 4; ++j) {
                int nn_x = n_x + dx[j];
                int nn_y = n_y + dy[j];

                if (invalid(nn_x, nn_y, 5)) continue;
                if (nn_x == c_x && nn_y == c_y) continue;

                if (place[nn_x][nn_y] == 'P') {
                    return 0;
                }
            }

        }
    }

    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    int room_number = 1;
    for (auto place : places) {
        answer.push_back(check(place, room_number));
        room_number++;
    }


    return answer;
}
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    queue<int> progress_list;
    queue<int > speed_list;

    for (int i = 0; i < progresses.size(); ++i) {
        progress_list.push(progresses[i]);
        speed_list.push(speeds[i]);
    }

    while (progress_list.size() > 0) {
        int num = 0;
        while (progress_list.size() > 0 && progress_list.front() >= 100) {
            num += 1;
            progress_list.pop();
            speed_list.pop();
        }

        if (num > 0)
            answer.push_back(num);

        for (int i = 0; i < progress_list.size(); ++i) {
            progress_list.push(progress_list.front() + speed_list.front());
            speed_list.push(speed_list.front());
            progress_list.pop();
            speed_list.pop();
        }
    }

    return answer;
}
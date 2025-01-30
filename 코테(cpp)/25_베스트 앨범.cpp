#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <tuple>
#include <iostream>
#include <algorithm>
using namespace std;

class Compare
{
public:
    bool operator() (const tuple<int, int>& a, const tuple<int, int>& b) {
        auto& [a_play, a_id] = a;
        auto& [b_play, b_id] = b;

        if (a_play == b_play) return a_id > b_id;
        return a_play < b_play;
    }
};

//재생수가 더 많은 장르 순으로
bool compare_B(const tuple<string, int>& a, const tuple<string, int>& b) {
    return get<1>(a) > get<1>(b);
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> genres_playSum;
    unordered_map<string, priority_queue<tuple<int, int>, vector<tuple<int, int>>, Compare>> mem;
    for (int i = 0; i < genres.size(); ++i) {
        genres_playSum[genres[i]] += plays[i];
        mem[genres[i]].push({ plays[i], i });
    }

    //genres_playSum을 벡터로
    vector<tuple<string, int>> genres_playSum_v(genres_playSum.begin(), genres_playSum.end());
    sort(genres_playSum_v.begin(), genres_playSum_v.end(), compare_B);


    for (auto& [genre, play] : genres_playSum_v) {
        for (int i = 0; i < 2; ++i) {
            if (!mem[genre].empty()) {
                auto [play, id] = mem[genre].top();
                mem[genre].pop();
                answer.push_back(id);
            }
        }
    }
    return answer;
}
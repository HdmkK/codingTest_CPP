#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cmath>
using namespace std;

int max_value = 0;
//매 재귀호출마다, 현재 선택한 것을 제외한 던전중 하나를 고른다.
//모든 던전을 방문 or 피로도 충족을 못하면 백트래킹
void DFS(vector<vector<int>>& dungeons, unordered_set<int>& mem, int fatigue, int N) {

    //만약 모든 던전을 탐험했다면 최댓값 갱신
    if (mem.size() == N) {
        max_value = max(max_value, static_cast<int>(mem.size()));
        return;
    }

    for (int i = 0; i < dungeons.size(); ++i) {
        if (mem.find(i) == mem.end()) {
            if (fatigue >= dungeons[i][0]) {
                //아직 방문안했고 방문하기에 피로도가 충분하다면 방문
                mem.insert(i);
                DFS(dungeons, mem, fatigue - dungeons[i][1], N);
                mem.erase(i);//다음 경우의 수를 위해 원래상태로 복구
            }
            else {//다음 던전을 탐험하진 않았지만 피로도가 부족하여 더이상 진행할 수 없을 때
                //더이상 못가므로 최대값을 갱신(insert를 안하므로 백트래킹한거나 마찬가지)
                max_value = max(max_value, static_cast<int>(mem.size()));
            }
        }
    }

}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    unordered_set<int> mem;
    DFS(dungeons, mem, k, dungeons.size());
    return max_value;
}
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, string> parent;
unordered_map<string, int> mem;
void dfs(string name, int incentive) {
    if (name == "-") return;//끝까지 올라감
    if (incentive == 0) return;//더이상 거슬러 올라갈 필요X(앞으로도 incentive는 0일 것이므로)
    mem[name] += incentive - (incentive / 10);//현재 멤버에 대해서 이익 누적
    string parent_name = parent[name];//부모 갱신

    dfs(parent_name, incentive / 10);//부모에 대해서 처리
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;

    //부모 참조용 맵, 각 멤버의 이익을 저장할 맵을 초기화
    for (int i = 0; i < enroll.size(); ++i) {
        parent.insert(make_pair(enroll[i], referral[i]));
        mem.insert(make_pair(enroll[i], 0));
    }
    
    //각 판매기록에 대해서 -> 재귀로 거슬러 올라가면서 이익을 누적
    for (int i = 0; i < seller.size(); ++i) {
        dfs(seller[i], amount[i] * 100);
    }

    //이익들을 배열에 차례대로 저장
    for (int i = 0; i < enroll.size(); ++i) {
        answer.push_back(mem[enroll[i]]);
    }
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> candidate;
vector<int> apeachInfo;
vector<int> arr;
int maxDiff = 0;


//라이언이 점수를 가져가는 경우의 수(조합)을 구함.
void dfs(int start, int restArrow, int k, int cnt) {

    if (cnt == k) {

        int rianSum = 0;
        int apeachSum = 0;

        for (int i = 0; i <= 10; ++i) {
            if (arr[i] > 0) {
                rianSum += (10 - i);
                continue;
            }

            if (apeachInfo[i] > 0) {
                apeachSum += (10 - i);
            }
        }



        if (maxDiff <= (rianSum - apeachSum)) {


            vector<int> temp = arr;

            //화살이 남았으면, 결과를 바꾸지 않는 선에서 가장 오른쪽에 더함.
            for (int i = 10; i >= 0; --i) {
                if (temp[i] > apeachInfo[i]) { //이긴 점수일 경우
                    temp[i] += restArrow;
                    break;
                }
                else if (temp[i] <= apeachInfo[i]) { // 진 점수일 경우
                    if (temp[i] + restArrow <= apeachInfo[i]) {
                        temp[i] += restArrow;
                        break;
                    }
                }
            }


            //만약 점수차가 최대와 동일하다면 -> 우선순위에 따라 후보만 갱신
            if (maxDiff > 0 && maxDiff == (rianSum - apeachSum)) {

                for (int i = 10; i >= 0; --i) {
                    if (candidate[i] < temp[i]) {
                        candidate = temp;
                        return;
                    }
                }
            }
            else {//더 큰 점수차이므로 -> 최대 점수차를 갱신하고, 후보 또한 갱신

                maxDiff = (rianSum - apeachSum);

                candidate = temp;
            }

        }


        return;
    }

    for (int i = start; i <= 10; ++i) {

        if ((restArrow - (apeachInfo[i] + 1)) >= 0) {
            arr[i] = (apeachInfo[i] + 1);
            dfs(i + 1, restArrow - (apeachInfo[i] + 1), k, cnt + 1);
            arr[i] = 0;
        }
    }
}

vector<int> solution(int n, vector<int> info) {

    apeachInfo = info;

    for (int k = 0; k <= 10; ++k) {
        arr.assign(11, 0);
        dfs(0, n, k, 0);
    }

    if (maxDiff == 0) return { -1 };

    return candidate;
}
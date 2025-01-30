//아래 코드는 테스트 코드 입니다.
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm> // sort, unique를 위해 선언
#include <set>
using namespace std;
bool compare(const int& a, const int& b) {
    return a > b;
}

vector<int> solution(vector<int> lst) {
    sort(lst.begin(), lst.end(), compare);
    lst.erase(unique(lst.begin(), lst.end()), lst.end());
    return lst;
}


void print(vector<int> vec)
{
    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    print(solution({ 4, 2, 2, 1, 1, 3, 4 })); // 4 3 2 1  
    print(solution({ 2, 1, 1, 3, 2, 5, 4 })); // 5 4 3 2 1

    return 0;
}
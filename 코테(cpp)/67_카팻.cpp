#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int x, y;

    x = ((brown - 4) / 2 + sqrt(pow((4 - brown) / 2, 2) - (4 * yellow))) / 2;
    y = yellow / x;

    return (x > y) ? vector<int>{x + 2, y + 2} : vector<int>{ y + 2, x + 2 };
}
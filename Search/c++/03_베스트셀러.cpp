// fast campus 강의
// https://www.acmicpc.net/problem/1302
// 1

#include <iostream>
#include <map>

using namespace std;

int N;
map<string, int> book;

int main() 
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        book[s] += 1;
    }

    int max_value = 0;
    string result;
    for (auto b : book) {
        if (max_value < b.second) {
            max_value = b.second;
            result = b.first;
        }
    }

    cout << result;
}
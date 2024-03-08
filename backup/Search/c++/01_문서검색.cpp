// fast campus 강의
// https://www.acmicpc.net/problem/1543
// 2

#include <iostream>

using namespace std;

int main()
{
    string document;
    getline(cin, document);
    string word;
    getline(cin, word);

    int idx = 0, result = 0;
    while (document.length() - idx >= word.length()) {
        if (word == document.substr(idx, word.length())) {
            result++;
            idx += word.length();
        } else {
            idx++;
        }
    }
    cout << result;
}
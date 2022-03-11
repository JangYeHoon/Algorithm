// fast campus 강의
// https://www.acmicpc.net/problem/1092
// 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> box;
vector<int> crane;

bool comp(long a, long b) {
	return a > b;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        crane.push_back(tmp);
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int tmp;
        cin >> tmp;
        box.push_back(tmp);
    }
    sort(box.begin(), box.end(), comp);
	sort(crane.begin(), crane.end(), comp);

    int result = 0;
    if (crane[0] < box[0])
        result = -1;
    else {
        while (1) {
            if (box.size() == 0)
                break;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < box.size(); j++) {
                    if (crane[i] >= box[j]) {
                        box.erase(box.begin() + j);
                        break;
                    }
                }
            }
            result += 1;
        }
    }
    cout << result;
}
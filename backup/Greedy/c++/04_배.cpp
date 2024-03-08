// fast campus 강의
// https://www.acmicpc.net/problem/1092
// 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> crane;
vector<int> box;

int position[51];
bool checkd[10001];

bool comp(int a, int b) {
	return a > b;
}

int main()
{
	int temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		crane.push_back(temp);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		box.push_back(temp);
	}

	sort(crane.begin(), crane.end(), comp);
	sort(box.begin(), box.end(), comp);

	int result = 0;
	if (crane[0] < box[0])
		result = -1;
	else {
		int count = 0;
		while (1) {
			if (count == M)
				break;
			for (int i = 0; i < N; i++) {
				while (position[i] < M) {
					if (!checkd[position[i]] && crane[i] >= box[position[i]]) {
						checkd[position[i]] = true;
						position[i]++;
						count++;
						break;
					}
					position[i]++;
				}
			}
			result++;
		}
	}
	cout << result;
}

// int main()
// {
//     cin >> N;
//     for (int i = 0; i < N; i++) {
//         int tmp;
//         cin >> tmp;
//         crane.push_back(tmp);
//     }

//     cin >> M;
//     for (int i = 0; i < M; i++) {
//         int tmp;
//         cin >> tmp;
//         box.push_back(tmp);
//     }
//     sort(box.begin(), box.end(), comp);
// 	sort(crane.begin(), crane.end(), comp);

//     int result = 0;
//     if (crane[0] < box[0])
//         result = -1;
//     else {
//         while (1) {
//             if (box.size() == 0)
//                 break;
//             for (int i = 0; i < N; i++) {
//                 for (int j = 0; j < box.size(); j++) {
//                     if (crane[i] >= box[j]) {
//                         box.erase(box.begin() + j);
//                         break;
//                     }
//                 }
//             }
//             result += 1;
//         }
//     }
//     cout << result;
// }
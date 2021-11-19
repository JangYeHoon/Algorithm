//
// https://www.acmicpc.net/source/35583700
// 1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> card(N);
	vector<bool> comb(N);
	for (int i = 0; i < N; i++) {
		cin >> card[i];
		comb[i] = false;
	}
	for (int i = 0; i < 3; i++)
		comb[i] = true;

	sort(comb.begin(), comb.end());

	int result = 0;
	do {
		int tmp = 0;
		for (int i = 0; i < N; i++) {
			if (comb[i]) {
				tmp += card[i];
			}
		}
		if (tmp <= M) {
			result = max(result, tmp);
		}

	} while (next_permutation(comb.begin(), comb.end()));

	cout << result << endl;

	return 0;
}

// 다른 풀이
// int main()
// {
// 	int N, M;
// 	cin >> N >> M;
// 	vector<int> card(N);
// 	for (int i = 0; i < N; i++)
// 		cin >> card[i];

// 	int result = 0;
// 	for (int i = 0; i < N; i++) {
// 		for (int j = i + 1; j < N; j++) {
// 			for (int k = j + 1; k < N; k++) {
// 				int tmp = card[i] + card[j] + card[k];
// 				if (tmp <= M)
// 					result = max(result, tmp);
// 			}
// 		}
// 	}

// 	cout << result << endl;

// 	return 0;
// }
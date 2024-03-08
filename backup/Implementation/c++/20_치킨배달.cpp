// 이것이 취업을 위한 코딩테스트다 332p
// https://www.acmicpc.net/problem/15686
// 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<pair<int, int>> chicken_matrix;
vector<pair<int, int>> house_matrix;

int getSum(vector<pair<int, int>> chickens)
{
	int sum = 0;
	for (int i = 0; i < house_matrix.size(); i++) {
		int hx = house_matrix[i].first;
		int hy = house_matrix[i].second;
		int dist = 1e9;
		for (int j = 0; j < chickens.size(); j++) {
			int cx = chickens[j].first;
			int cy = chickens[j].second;
			dist = min(dist, abs(hx - cx) + abs(hy - cy));
		}
		sum += dist;
	}
	return sum;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			if (temp == 1)
				house_matrix.push_back({ i, j });
			else if (temp == 2)
				chicken_matrix.push_back({ i, j });
		}
	}

	vector<bool> p(chicken_matrix.size());
	fill(p.end() - M, p.end(), true);
	int result = 1e9;
	do {
		vector<pair<int, int>> chickens;
		for (int i = 0; i < chicken_matrix.size(); i++)
			if (p[i])
				chickens.push_back(chicken_matrix[i]);
		result = min(result, getSum(chickens));
	} while (next_permutation(p.begin(), p.end()));

	cout << result;
}
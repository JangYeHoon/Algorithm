// 이것이 취업을 위한 코딩테스트다 332p
// https://www.acmicpc.net/problem/15686
// 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int getSum(vector<pair<int, int>> chicken_temp)
{
	int result = 0;
	for (int i = 0; i < house.size(); i++)
	{
		int hx = house[i].first;
		int hy = house[i].second;
		int temp = 1e9;
		for (int j = 0; j < chicken_temp.size(); j++)
		{
			int cx = chicken_temp[j].first;
			int cy = chicken_temp[j].second;
			temp = min(temp, abs(hx - cx) + abs(hy - cy));
		}
		result += temp;
	}
	return result;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp = 0;
			cin >> temp;
			if (temp == 1)
				house.push_back({ i, j });
			else if (temp == 2)
				chicken.push_back({ i, j });
		}
	}

	vector<bool> v(chicken.size());
	fill(v.end() - m, v.end(), true);

	int result = 1e9;
	do
	{
		vector<pair<int, int>> chicken_temp;
		for (int i = 0; i < chicken.size(); i++)
		{
			if (v[i])
			{
				int x = chicken[i].first;
				int y = chicken[i].second;
				chicken_temp.push_back({ x, y });
			}
		}
		result = min(result, getSum(chicken_temp));
	} while (next_permutation(v.begin(), v.end()));

	cout << result << '\n';
	return 0;
}
// 이것이 취업을 위한 코딩테스트다 349p
// https://www.acmicpc.net/problem/14888
// 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<int> number(n);
	for (int i = 0; i < n; i++)
		cin >> number[i];

	vector<int> op;
	for (int i = 0; i < 4; i++)
	{
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++)
			op.push_back(i);
	}

	sort(op.begin(), op.end());

	int max_n = -1e9;
	int min_n = 1e9;
	do
	{
		int result = number[0];
		int index = 0;
		for (int i = 1; i < n; i++)
		{
			if (op[index] == 0)
				result += number[i];
			else if (op[index] == 1)
				result -= number[i];
			else if (op[index] == 2)
				result *= number[i];
			else if (op[index] == 3)
			{
				int temp = result;
				if (number[i] < 0)
				{
					temp /= (-number[i]);
					result = -temp;
				}
				else
					result /= number[i];
			}
			index += 1;
		}
		max_n = max(max_n, result);
		min_n = min(min_n, result);
	} while (next_permutation(op.begin(), op.end()));

	cout << max_n << '\n';
	cout << min_n << '\n';
}
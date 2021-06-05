#include <iostream>
#include <algorithm>

using namespace std;

int coin[4] = { 500, 100, 50, 1 };

int min_coin_count(int value)
{
	int total_coint_count = 0;
	int details[4] = { 0, };
	for (int i = 0; i < 4; i++)
	{
		int coin_num = value / coin[i];
		total_coint_count += coin_num;
		value -= coin_num * coin[i];
		details[i] = coin_num;
	}
	for (int i = 0; i < 4; i++)
		cout << coin[i] << '-' << details[i] << ' ';
	cout << endl;
	return total_coint_count;
}

int main()
{
	cout << min_coin_count(4720) << endl;
	return 0;
}
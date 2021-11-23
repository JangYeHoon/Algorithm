// fast campus 강의
// https://www.acmicpc.net/problem/2920
// 1

#include <iostream>
using namespace std;

int main()
{
	int arr[8];
	bool ascending = true, descending = true;

	for (int i = 0; i < 8; i++)
		cin >> arr[i];

	for (int i = 0; i < 7; i++) {
		if (arr[i] + 1 != arr[i + 1])
			ascending = false;
		if (arr[i] - 1 != arr[i + 1])
			descending = false;
	}

	if (ascending)
		cout << "ascending" << endl;
	else if (descending)
		cout << "descending" << endl;
	else
		cout << "mixed" << endl;

	return 0;
}
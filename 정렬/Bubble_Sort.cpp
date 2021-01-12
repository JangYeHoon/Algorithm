#include <iostream>

using namespace std;

int main()
{
	int n[5] = { 5, 2, 4, 3, 1 };

	for (int i = 0; i < 5 - 1; i++)
	{
		bool check = false;
		for (int j = 0; j < 5 - 1 - i; j++)
		{
			if (n[j] > n[j + 1])
			{
				swap(n[j], n[j + 1]);
				check = true;
			}
		}
		if (check == false)
			break;
	}

	for (int i = 0; i < 5; i++)
		cout << n[i] << " ";
	cout << endl;
	return 0;
}
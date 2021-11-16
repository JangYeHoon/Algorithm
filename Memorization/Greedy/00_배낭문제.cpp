#include <iostream>
#include <algorithm>

using namespace std;

struct Data{
	int weight, val;
};

Data data_list[5] = { { 10, 10 }, { 15, 12 }, { 20, 10 }, { 25, 8 }, { 30, 5 } };

float get_max_value(float capacity)
{
	float details[5] = { 0, };
	float total_value = 0;

	for (int i = 0; i < 5; i++)
	{
		if (capacity - data_list[i].weight >= 0)
		{
			capacity -= data_list[i].weight;
			total_value += data_list[i].val;
			details[i] = 1;
		}
		else
		{
			float fraction = capacity / data_list[i].weight;
			total_value += data_list[i].val * fraction;
			details[i] = fraction;
			break;
		}
	}

	for (int i = 0; i < 5; i++)
		cout << data_list[i].weight << '-' << details[i] << ' ';
	cout << endl;

	return total_value;
}

int main()
{
	cout << get_max_value(30) << endl;
}
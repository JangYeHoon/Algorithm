#include <iostream>
#include <vector>

using namespace std;

vector<int> final_result;

bool is_available(vector<int> candidate, int col)
{
	int current_row = candidate.size();
	for (int row = 0; row < current_row; row++)
	{
		if (candidate[row] == col || abs(candidate[row] - col) == current_row - row)
			return false;
	}
	return true;
}

void solve_n_queens(int n, int current_row, vector<int> current_candidate)
{
	if (current_row == n)
	{
		for (int i = 0; i < current_candidate.size(); i++)
			final_result.push_back(current_candidate[i]);
		return;
	}

	for (int col = 0; col < n; col++)
	{
		if (is_available(current_candidate, col))
		{
			current_candidate.push_back(col);
			solve_n_queens(n, current_row + 1, current_candidate);
			current_candidate.pop_back();
		}
	}
}

int main(void)
{
	vector<int> current_candidate;
	int n;
	cin >> n;
	solve_n_queens(n, 0, current_candidate);

	for (int i = 0; i < final_result.size(); i++)
	{
		if (i % n == 0)
			cout << "[ ";
		cout << final_result[i] << " ";
		if (i % n == n-1)
			cout << "], ";
	}
}
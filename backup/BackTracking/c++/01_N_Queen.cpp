#include <iostream>
#include <vector>
using namespace std;

int n, result;
int arr[15];

bool is_available(int row)
{
    for (int i = 0; i < row; i++) {
        if (arr[row] == arr[i] || abs(arr[row] - arr[i]) == row - i)
            return false;
    }
    return true;
}

void dfs(int row)
{
    if (row == n) {
        result += 1;
        return;
    }
    else {
        for (int i = 0; i < n; i++) {
            arr[row] = i;
            if (is_available(row))
                dfs(row + 1);
        }
    }
}

int main()
{
    cin >> n;
    dfs(0);
    cout << result;
    return 0;
}
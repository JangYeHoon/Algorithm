// 이것이 취업을 위한 코딩테스트다 325p
// https://programmers.co.kr/learn/courses/30/lessons/60059
// 2

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rotate90(vector<vector<int>> key)
{
    int M = key.size();
    vector<vector<int>> new_key(M, vector<int>(M));
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            new_key[j][M - i - 1] = key[i][j];
    return new_key;
}

bool lock_chk(vector<vector<int>> lock)
{
    int N = lock.size() / 3;
    for (int i = N; i < N * 2; i++)
        for (int j = N; j < N * 2; j++)
            if (lock[i][j] != 1)
                return false;
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int N = lock.size();
    int M = key.size();
    vector<vector<int>> new_lock(N * 3, vector<int>(N * 3));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            new_lock[i + N][j + N] = lock[i][j];

    for (int x = 0; x < N * 2; x++) {
        for (int y = 0; y < N * 2; y++) {
            for (int k = 0; k < 4; k++) {
                key = rotate90(key);
                for (int i = 0; i < M; i++)
                    for (int j = 0; j < M; j++)
                        new_lock[x + i][y + j] += key[i][j];
                if (lock_chk(new_lock))
                    return true;
                for (int i = 0; i < M; i++)
                    for (int j = 0; j < M; j++)
                        new_lock[x + i][y + j] -= key[i][j];
            }
        }
    }
    return false;
}
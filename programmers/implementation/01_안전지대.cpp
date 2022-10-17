// https://school.programmers.co.kr/learn/courses/30/lessons/120866?language=cpp

#include <string>
#include <vector>

using namespace std;

int new_board[101][101];
int mx[8] = {1, -1, 0, 0, -1, -1, 1, 1};
int my[8] = {0, 0, 1, -1, 1, -1, 1, -1};

int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1) {
                new_board[i][j] = 1;
                for (int k = 0; k < 8; k++) {
                    int nx = i + mx[k];
                    int ny = j + my[k];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;
                    new_board[nx][ny] = 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (new_board[i][j] == 0)
                answer += 1;
    }
    return answer;
}
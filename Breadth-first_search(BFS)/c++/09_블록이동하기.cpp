// 이것이 취업을 위한 코딩테스트다
// https://school.programmers.co.kr/learn/courses/30/lessons/60063
// 1

#include <string>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int pX1;
    int pY1;
    int pX2;
    int pY2;
    Node(int pX1, int pY1, int pX2, int pY2) {
        this->pX1 = pX1;
        this->pY1 = pY1;
        this->pX2 = pX2;
        this->pY2 = pY2;
    }
};

vector<Node> get_next_pos(Node pos, vector<vector<int>> board) {
    vector<Node> next_pos;
    int mx[4] = { -1, 0, 1, 0 };
    int my[4] = { 0, -1, 0, 1 };
    for (int i = 0; i < 4; i++) {
        int nx1 = pos.pX1 + mx[i];
        int ny1 = pos.pY1 + my[i];
        int nx2 = pos.pX2 + mx[i];
        int ny2 = pos.pY2 + my[i];
        if (board[nx1][ny1] == 0 && board[nx2][ny2] == 0)
            next_pos.push_back(Node(nx1, ny1, nx2, ny2));
    }

    int hor[2] = { -1, 1 };
    if (pos.pX1 == pos.pX2) {
        for (int i = 0; i < 2; i++) {
            if (board[pos.pX1 + hor[i]][pos.pY1] == 0 && board[pos.pX2 + hor[i]][pos.pY2] == 0) {
                next_pos.push_back(Node(pos.pX1, pos.pY1, pos.pX1 + hor[i], pos.pY1));
                next_pos.push_back(Node(pos.pX2, pos.pY2, pos.pX2 + hor[i], pos.pY2));
            }
        }
    }
    int ver[2] = { -1, 1 };
    if (pos.pY1 == pos.pY2) {
        for (int i = 0; i < 2; i++) {
            if (board[pos.pX1][pos.pY1 + ver[i]] == 0 && board[pos.pX2][pos.pY2 + ver[i]] == 0) {
                next_pos.push_back(Node(pos.pX1, pos.pY1, pos.pX1, pos.pY1 + ver[i]));
                next_pos.push_back(Node(pos.pX2, pos.pY2, pos.pX2, pos.pY2 + ver[i]));
            }
        }
    }
    return next_pos;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    int N = board.size();
    vector<vector<int>> new_board(N + 2, vector<int>(N + 2, 1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            new_board[i + 1][j + 1] = board[i][j];
    }

    Node pos = Node(1, 1, 1, 2);
    queue<pair<Node, int>> q;
    q.push({ pos, 0 });
    vector<Node> visited;
    visited.push_back(pos);
    while (!q.empty()) {
        Node pos = q.front().first;
        int cost = q.front().second;
        q.pop();
        if ((pos.pX1 == N && pos.pY1 == N) || (pos.pX2 == N && pos.pY2 == N))
            return cost;

        vector<Node> next_pos = get_next_pos(pos, new_board);
        for (int i = 0; i < next_pos.size(); i++) {
            bool check = true;
            Node pos = next_pos[i];
            for (int j = 0; j < visited.size(); j++) {
                if (pos.pX1 == visited[j].pX1 && pos.pX2 == visited[j].pX2 && pos.pY1 == visited[j].pY1 && pos.pY2 == visited[j].pY2) {
                    check = false;
                    break;
                }
            }
            if (check) {
                q.push({ pos, cost + 1 });
                visited.push_back(pos);
            }
        }
    }
    return answer;
}
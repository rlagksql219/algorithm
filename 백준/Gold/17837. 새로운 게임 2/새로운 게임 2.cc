#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int N, K;
int map[13][13];
vector<tuple<int, int, int>> v;
vector<int> board[13][13];
int ans;

void move(int from_x, int from_y, int to_x, int to_y, bool mark, int idx) {
    vector<int>& from = board[from_x][from_y];
    vector<int>& to = board[to_x][to_y];

    // idx 이후의 말만 이동
    auto it = find(from.begin(), from.end(), idx);
    vector<int> moving_pieces(it, from.end());

    if (mark) {
        reverse(moving_pieces.begin(), moving_pieces.end());
    }

    for (int i : moving_pieces) {
        get<0>(v[i]) = to_x;
        get<1>(v[i]) = to_y;
        to.push_back(i);
    }

    // 이동한 말들을 원래 위치에서 제거
    from.erase(it, from.end());
}

bool finish_check() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j].size() >= 4) return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < K; i++) {
        int x, y, dir;
        cin >> x >> y >> dir;
        x--; y--;
        v.push_back({x, y, dir});
        board[x][y].push_back(i);
    }

    for (int turn = 1; turn <= 1000; turn++) {
        for (int i = 0; i < K; i++) {
            int cur_x = get<0>(v[i]);
            int cur_y = get<1>(v[i]);
            int dir = get<2>(v[i]);

            int next_x = cur_x;
            int next_y = cur_y;

            if (dir == 1) next_y++;
            else if (dir == 2) next_y--;
            else if (dir == 3) next_x--;
            else next_x++;

            // 파란색일 때 방향 변경
            if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N || map[next_x][next_y] == 2) {
                if (dir == 1) dir = 2;
                else if (dir == 2) dir = 1;
                else if (dir == 3) dir = 4;
                else dir = 3;
                get<2>(v[i]) = dir;

                next_x = cur_x;
                next_y = cur_y;
                if (dir == 1) next_y++;
                else if (dir == 2) next_y--;
                else if (dir == 3) next_x--;
                else next_x++;

                if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N || map[next_x][next_y] == 2) {
                    continue;
                }
            }

            // 말 이동
            if (map[next_x][next_y] == 1) { // 빨간색
                move(cur_x, cur_y, next_x, next_y, true, i);
            } else { // 흰색
                move(cur_x, cur_y, next_x, next_y, false, i);
            }

            // 종료 조건 체크
            if (finish_check()) {
                cout << turn;
                return 0;
            }
        }
    }

    cout << -1;
    return 0;
}

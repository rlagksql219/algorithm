#include <iostream>
#include <queue>

using namespace std;

/*
2차원 토마토
*/

int M, N;
int map[1000][1000];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

queue<pair<int, int>> q;

void bfs() {

	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = yy + dy[i];
			int nx = xx + dx[i];

			if (nx >= 0 && nx < M && ny >= 0 && ny < N && map[ny][nx] == 0) {
				map[ny][nx] = map[yy][xx] + 1;
				q.push({ ny, nx });
			}
		}
	}
}


int main() {
	int ans = 0;

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				q.push({ i, j });
		}
	}

	bfs();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				cout << -1;
				return 0;
			}

			if (map[i][j] > ans)
				ans = map[i][j];
		}
	}

	cout << ans - 1;

	return 0;
}
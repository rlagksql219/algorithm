#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

/*
3차원 토마토
*/

int M, N, H;
int map[100][100][100];

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

queue<tuple<int, int, int>> q;

void bfs() {

	while (!q.empty()) {
		int zz = get<0>(q.front());
		int yy = get<1>(q.front());
		int xx = get<2>(q.front());
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nz = zz + dz[i];
			int ny = yy + dy[i];
			int nx = xx + dx[i];

			if (nx >= 0 && nx < M && ny >= 0 && ny < N && nz >= 0 && nz < H && map[nz][ny][nx] == 0) {
				map[nz][ny][nx] = map[zz][yy][xx] + 1;
				q.push({ nz, ny, nx });
			}
		}
	}
}


int main() {
	int ans = 0;

	cin >> M >> N >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> map[i][j][k];
				if (map[i][j][k] == 1)
					q.push({ i, j, k });
			}
		}
	}

	bfs();

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (map[i][j][k] == 0) {
					cout << -1;
					return 0;
				}

				if (map[i][j][k] > ans)
					ans = map[i][j][k];
			}
		}
	}

	cout << ans - 1;

	return 0;
}
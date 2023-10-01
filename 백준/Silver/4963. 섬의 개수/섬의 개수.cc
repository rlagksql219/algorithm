#include <iostream>
#include <string.h>
#include <queue>

int w, h;
int map[51][51] = {-1};
bool visited[51][51];
int ans;

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

using namespace std;

void bfs(int x, int y) {
	visited[x][y] = true;

	queue<pair<int, int>> q;

	q.push({ x,y });
	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;

		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			if (nx >= 0 && nx < w && ny >= 0 && ny < h && map[nx][ny] == 1 && !visited[nx][ny]) {
				q.push({ nx, ny });
				visited[nx][ny] = true;
			}
		}
	}

	ans++;
}

int main() {

	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0)	break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				int tmp;
				cin >> tmp;
				map[j][i] = tmp;
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[j][i] == 1 && !visited[j][i])
					bfs(j, i);
			}
		}

		cout << ans << '\n';

		//초기화
		w = 0, h = 0, ans = 0;
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));
	}

	return 0;
}
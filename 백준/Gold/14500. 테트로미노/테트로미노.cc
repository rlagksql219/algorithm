#include <iostream>

using namespace std;

int N, M;
int map[501][501];
bool visited[501][501];
int ans;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void dfs(int x, int y, int depth, int sum) {
	visited[x][y] = true;
	sum += map[x][y];

	if (depth == 4) {
		ans = max(sum, ans);
		visited[x][y] = false;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny]) {
			dfs(nx, ny, depth + 1, sum);
		}
	}
	visited[x][y] = false;

	// ㅓ
	if (x - 1 >= 0 && y - 1 >= 0 && y + 1 < M)
		ans = max(ans, map[x][y] + map[x - 1][y] + map[x][y - 1] + map[x][y + 1]);
	// ㅏ
	if (x + 1 < N && y - 1 >= 0 && y + 1 < M)
		ans = max(ans, map[x][y] + map[x + 1][y] + map[x][y - 1] + map[x][y + 1]);
	// ㅗ
	if (x - 1 >= 0 && x + 1 < N && y + 1 < M)
		ans = max(ans, map[x][y] + map[x - 1][y] + map[x + 1][y] + map[x][y + 1]);
	// ㅜ
	if (x - 1 >= 0 && x + 1 < N && y - 1 >= 0)
		ans = max(ans, map[x][y] + map[x - 1][y] + map[x + 1][y] + map[x][y - 1]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			dfs(i, j, 1, 0);
		}
	}

	cout << ans;

	return 0;
}
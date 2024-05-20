#include <iostream>
#include <vector>

using namespace std;

int N, M;
char arr[21][21];
bool visited[26];
int ans = 0;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(int x, int y, int cnt) {
	int index = arr[x][y] - 'A';
	visited[index] = true;
	ans = max(ans, cnt);

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
			int index2 = arr[nx][ny] - 'A';
			if (!visited[index2]) {
				visited[index2] = true;
				dfs(nx, ny, cnt + 1);
				visited[index2] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c;
			cin >> c;
			arr[i][j] = c;
		}
	}

	dfs(0, 0, 1);
	cout << ans;

	return 0;
}
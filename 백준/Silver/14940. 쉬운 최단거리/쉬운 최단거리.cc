#include <iostream>
#include <queue>

using namespace std;

int n, m;
int arr[1001][1001];
bool visited[1001][1001];
int cnt[1001][1001];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs(int x, int y) {
	visited[x][y] = true;

	queue <pair<int, int>> q;
	q.push({ x, y });

	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && arr[nx][ny] != 0) {
				q.push({ nx, ny });
				visited[nx][ny] = true;
				cnt[nx][ny] = cnt[xx][yy] + 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 2) {
				bfs(i, j);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1 && cnt[i][j] == 0) {
				cnt[i][j] = -1;
			}

			cout << cnt[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}
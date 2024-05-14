#include <iostream>
#include <queue>

using namespace std;

int N;
int arr[130][130];
bool visited[130][130];
int cnt[130][130];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


void bfs(int x, int y) {
	visited[x][y] = true;
	cnt[x][y] = arr[x][y];

	queue <pair<int, int>> q;
	q.push({ x, y });
	
	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (cnt[nx][ny] > cnt[xx][yy] + arr[nx][ny]) {
					cnt[nx][ny] = cnt[xx][yy] + arr[nx][ny];
					visited[nx][ny] = true;
					q.push({ nx, ny });
				}
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num = 1;
	for (int i = 0; i < 130; i++) {
		for (int j = 0; j < 130; j++) {
			cnt[i][j] = 987654321;
		}
	}

	while (1) {
		cin >> N;
		if (N == 0)	break;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int tmp;
				cin >> tmp;
				arr[i][j] = tmp;
			}
		}
		bfs(0,0);

		cout << "Problem " << num << ": " << cnt[N - 1][N - 1] << '\n';

		N = 0;
		for (int i = 0; i < 130; i++) {
			for (int j = 0; j < 130; j++) {
				arr[i][j] = 0;
				visited[i][j] = false;
				cnt[i][j] = 987654321;
			}
		}
		num++;
	}

	return 0;
}
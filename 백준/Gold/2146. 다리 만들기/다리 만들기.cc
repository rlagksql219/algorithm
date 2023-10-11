#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

int N;
int cnt = 1;
int map[101][101];
bool visited[101][101];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void original_bfs(int x, int y, int cnt) {
	visited[x][y] = true;
	map[x][y] = cnt;

	queue<pair<int, int>> q;

	q.push({ x, y });
	
	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;

		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && map[nx][ny] == -1) {
				q.push({ nx, ny });
				visited[nx][ny] = true;
				map[nx][ny] = cnt;
			}
		}
	}
}


int bfs(int num) {
	int distance = 0;
	queue<pair<int, int>> q;

	//육지에 있는 모든 땅 queue에 넣어주기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == num) {
				visited[i][j] = true;
				q.push({ i, j });
			}
		}
	}

	while (!q.empty()) {
		int Q_size = q.size();
		for (int i = 0; i < Q_size; i++) {
			int xx = q.front().first;
			int yy = q.front().second;

			q.pop();
			for (int j = 0; j < 4; j++) {
				int nx = xx + dx[j];
				int ny = yy + dy[j];

				if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
					if (map[nx][ny] != 0 && map[nx][ny] != num) //바다 건너서 다른 육지에 도착
						return distance;
					else if (map[nx][ny] == 0 && !visited[nx][ny]) { //아직 방문하지 않은 바다
						q.push({ nx, ny });
						visited[nx][ny] = true;
					}
				}
			}
		}
		distance++;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ans = 1000000;

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;

			cin >> tmp;
			if (tmp == 1)
				map[i][j] = -1;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == -1) {
				original_bfs(i, j, cnt); //육지 번호 붙이기
				cnt++;
			}
		}
	}

	memset(visited, false, sizeof(visited));

	for (int i = 1; i < cnt; i++) {
		ans = min(ans, bfs(i));
		memset(visited, false, sizeof(visited));
	}

	cout << ans;

	return 0;
}
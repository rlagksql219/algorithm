#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

int N, L, R;
int arr[51][51];
bool visited[51][51];
int flag = true;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs(int x, int y) {
	visited[x][y] = true;
	queue<pair<int, int>> q;
	queue<pair<int, int>> calq;
	q.push({ x, y });
	calq.push({ x, y });

	int sum = 0;
	int country = 0;
	sum += arr[x][y];
	country++;

	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			int sub = abs(arr[xx][yy] - arr[nx][ny]);
			if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && sub >= L && sub <= R) {
				flag = true;
				visited[nx][ny] = true;
				q.push({ nx, ny });
				calq.push({ nx, ny });
				
				sum += arr[nx][ny];
				country++;
			}
		}
	}

	while (!calq.empty()) { //국경 공유한 나라들 간에 인구 공유
		int xx = calq.front().first;
		int yy = calq.front().second;
		arr[xx][yy] = sum / country;
		calq.pop();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ans = 0;
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			arr[i][j] = tmp;
		}
	}

	while (flag) {
		flag = false;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if(!visited[i][j])
					bfs(i, j);
			}
		}

		if(flag)
			ans++;
		memset(visited, false, sizeof(visited));
	}

	cout << ans;

	return 0;
}
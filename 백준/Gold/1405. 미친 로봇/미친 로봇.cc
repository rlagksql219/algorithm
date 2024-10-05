#include <iostream>

using namespace std;

int N;
double pro[4];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
bool visited[30][30];
double ans;

void dfs(int x, int y, double probability, int depth) {
	if (depth == N) {
		ans += probability;
		return;
	}

	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(!visited[nx][ny])
			dfs(nx, ny, probability * pro[i], depth + 1);
	}
	visited[x][y] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < 4; i++) {
		cin >> pro[i];
		pro[i] /= 100.0;
	}

	dfs(15, 15, 1.0, 0);

	cout.precision(16);
	cout << ans;

	return 0;
}
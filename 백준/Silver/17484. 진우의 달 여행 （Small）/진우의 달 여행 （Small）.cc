#include <iostream>

using namespace std;

int N, M;
int map[7][7];
int ans = 999999999;
int dx[3] = { -1, 0, 1 };

int Solve(int y, int x, int last) {
	if (y == N)	return 0;

	int tmp = 999999999;
	for (int i = 0; i < 3; i++) {
		if (x + dx[i] >= 0 && x + dx[i] < M && i != last)
			tmp = min(tmp, Solve(y + 1, x + dx[i], i) + map[y][x]);
	}

	return tmp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < M; i++)
		ans = min(ans, Solve(0, i, -1));

	cout << ans;
	
	return 0;
}
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

/*
https://velog.io/@rlagksql219/BOJC-3109-%EB%B9%B5%EC%A7%91-DFS
*/

int map[10001][501];
bool visited[10001][501];
int ans;
int dx[3] = {-1, 0, 1};
int dy[3] = {1, 1, 1};
int R, C;
bool check; //������ ���޿���

void dfs(int x, int y) {
	visited[x][y] = true;

	if (y == C) {
		ans++;
		check = true;
		return;
	}

	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 1 && ny >= 1 && nx <= R && ny <= C && !visited[nx][ny] && map[nx][ny] == 1) {
			dfs(nx, ny);
			if (check)	return; //������ �������� ���, �ٸ� �������� Ž�� ���ϵ��� !
		}
	}
}

int main() {

	cin >> R >> C;
	
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			char c;

			cin >> c;
			if (c == '.') {
				map[i][j] = 1;
			}
			else { //�ǹ��� �־ �� ���� ���
				map[i][j] = 0;
			}
		}
	}

	for (int i = 1; i <= R; i++) {
		check = false;
		dfs(i, 0);
	}

	cout << ans;

	return 0;
}
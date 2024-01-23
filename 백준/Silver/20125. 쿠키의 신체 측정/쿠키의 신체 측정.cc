#include <iostream>
#include <vector>

using namespace std;

int map[1001][1001];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int cenX = 0, cenY = 0;
	int la = 0, ra = 0, w = 0, ll = 0, rl = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char tmp;

			cin >> tmp;
			if (tmp == '*') {
				map[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1) {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int x = i + dx[k];
					int y = j + dy[k];
					if (map[x][y] == 1)	cnt++;
				}
				if (cnt == 4) {
					cenX = i;
					cenY = j;
				}
			}
		}
	}

	int x = cenX;
	int y = cenY - 1;
	while (1) {
		if (map[x][y] == 0)	break;
		la++;
		y--;
	}
	x = cenX;
	y = cenY + 1;
	while (1) {
		if (map[x][y] == 0)	break;
		ra++;
		y++;
	}
	x = cenX + 1;
	y = cenY;
	while (1) {
		if (map[x][y] == 0)	break;
		w++;
		x++;
	}
	y = cenY - 1;
	int X = x;
	int Y = y + 2;
	while (1) {
		if (map[x][y] == 0)	break;
		ll++;
		x++;
	}
	while (1) {
		if (map[X][Y] == 0)	break;
		rl++;
		X++;
	}

	cout << cenX+1 << " " << cenY+1 << '\n';
	cout << la << " " << ra << " " << w << " " << ll << " " << rl << '\n';

	return 0;
}
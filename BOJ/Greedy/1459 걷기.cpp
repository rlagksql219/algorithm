#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int x, y, w, s;
	long long ans = 0;
	int cx = 0, cy = 0;

	cin >> x >> y >> w >> s;
	while (1) {
		if (cx >= x || cy >= y)	break;

		if (2 * w < s) { //가로,세로 이동
			cx += 1;
			cy += 1;
			ans += 2 * w;
		}
		else { //대각선으로 이동
			cx += 1;
			cy += 1;
			ans += s;
		}
	}

	while (cx != x) {
		if (((x - cx) % 2 == 0) && (2*w > 2*s)) {
			cx += 2;
			ans += 2 * s;
			continue;
		}
		cx += 1;
		ans += w;
	}

	while (cy != y) {
		if (((y - cy) % 2 == 0) && (2*w > 2*s)) {
			cy += 2;
			ans += 2 * s;
			continue;
		}
		cy += 1;
		ans += w;
	}

	cout << ans;

	return 0;
}
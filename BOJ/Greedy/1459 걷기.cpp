#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int x, y, w, s;
	int ans = 0;
	int cx = 0, cy = 0;

	cin >> x >> y >> w >> s;
	while (cx >= x && cy >= y) {
		if (2 * w < s) { //����,���� �̵�
			cx += 1;
			cy += 1;
			ans += 2 * w;
		}
		else { //�밢������ �̵�
			cx += 1;
			cy += 1;
			ans += s;
		}
	}

 	while (cx != x) {
		cx += 1;
		ans += w;
	}

	while (cy != y) {
		cy += 1;
		ans += w;
	}

	cout << ans;
//

	return 0;
}
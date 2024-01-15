#include <iostream>
#include <vector>

using namespace std;

int main() {

	int h, w, n, m;
	int cnt1 = 0, cnt2 = 0;

	cin >> h >> w >> n >> m;

	for (int i = 1; i <= w; i++) {
		cnt1++;
		i += m;
	}

	for (int i = 1; i <= h; i++) {
		cnt2++;
		i += n;
	}

	cout << cnt1 * cnt2;

	return 0;
}
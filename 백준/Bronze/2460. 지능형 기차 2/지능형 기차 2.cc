#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int ans = 0;
	int cnt = 0;
	int a, b;

	for (int i = 0; i < 10; i++) {
		cin >> a >> b;
		cnt -= a;
		ans = max(ans, cnt);
		cnt += b;
		ans = max(ans, cnt);
	}

	cout << ans;

	return 0;
}
#include <iostream>

using namespace std;


int main() {
	int n;
	int ans = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		int cnt = 0;
		
		cin >> tmp;
		for (int j = 1; j <= tmp; j++) {
			if (tmp % j == 0) {
				cnt++;
			}
		}

		if (cnt == 2)	ans++;
	}

	cout << ans;

	return 0;
}
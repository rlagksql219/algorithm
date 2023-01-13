#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

/*
https://velog.io/@rlagksql219/BOJC-11501-%EC%A3%BC%EC%8B%9D-Greedy
*/

int main() {
	int T;

	cin >> T;
	while (T--) {
		int n;
		vector<int> v;
		int max = 0;
		long long ans = 0;

		cin >> n;
		for (int i = 0; i < n; i++) {
			int tmp;

			cin >> tmp;
			v.push_back(tmp);
		}

		max = v.back();
		for (int i = n-2; i >= 0; i--) {
			if (v[i] >= max) {
				max = v[i];
			}
			else {
				ans += max - v[i];
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
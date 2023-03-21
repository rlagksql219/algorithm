#include <iostream>

using namespace std;

int n, m;
int a[10001];

int main() {
	int cnt = 0, start = 0, end = 0, sum = 0;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	/* 투포인터 알고리즘 */
	while (end <= n) {
		if (sum < m) {
			sum += a[end];
			end++;
		}
		else {
			if (sum == m)	cnt++;
			sum -= a[start];
			start++;
		}
	}

	cout << cnt << endl;

	return 0;
}
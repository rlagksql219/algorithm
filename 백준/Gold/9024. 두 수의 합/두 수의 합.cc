#include <iostream>
#include <algorithm>
#include <cmath>
#include <string.h>

using namespace std;

int arr[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + n);

		int start = 0, end = n - 1, sum, diff = 987654321, cnt = 0;
		while (start < end) {
			sum = arr[start] + arr[end];
			int cur_diff = abs(k - sum);

			if (cur_diff < diff) {
				diff = cur_diff;
				cnt = 1;
			}
			else if (cur_diff == diff)	cnt++;

			if (sum <= k)	start++;
			else if (sum > k)	end--;
		}

		cout << cnt << '\n';
		memset(arr, 0, sizeof(arr));
	}

	return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

long long arr[100001];

int main() {
	int N;
	long long ans = 0;
	int cnt = 0;
	int max = 0;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);
	ans = arr[0];
	for (int i = 1; i < N; i++) {
		if (arr[i - 1] == arr[i]) {
			cnt++;

			if (cnt > max) {
				max = cnt;
				ans = arr[i];
			}
		}
		else
			cnt = 0;
	}

	cout << ans;

	return 0;
}
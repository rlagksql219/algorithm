#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, target;
	int ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> target;
	sort(arr, arr + n);

	int left = 0, right = n - 1, sum;
	while (left < right) {
		sum = arr[left] + arr[right];
		if (sum == target) {
			ans++;
			left++;
			right--;
		}
		else if (sum < target)	left++;
		else right--;
	}

	cout << ans;

	return 0;
}
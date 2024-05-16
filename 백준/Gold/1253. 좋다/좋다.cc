#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[2001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);
	for (int i = 0; i < N; i++) {
		int target = arr[i];
		int left = 0, right = N - 1, sum;
		while (left < right) {
			sum = arr[left] + arr[right];
			if (target == sum) {
				if (left != i && right != i) {
					ans++;
					break;
				}
				else if (left == i)	left++;
				else if (right == i)	right--;
			}
			else if (sum > target)	right--;
			else left++;
		}
	}

	cout << ans;

	return 0;
}
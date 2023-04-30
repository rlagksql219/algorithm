#include <iostream>

using namespace std;

int arr[10];

int main() {

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		cin >> cnt;

		for (int j = 0; j < n; j++) {
			if (cnt == 0 && arr[j] == 0) {
				arr[j] = i;
				break;
			}
			if (arr[j] == 0)	cnt--;
		}
	}

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}
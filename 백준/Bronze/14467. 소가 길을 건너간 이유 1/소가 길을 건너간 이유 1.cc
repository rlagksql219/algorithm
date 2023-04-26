#include <iostream>

using namespace std;

int arr[11] = { -1 };
int mark[11] = { 0 };

int main() {
	
	int n;
	int ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		if (arr[a] != -1 && arr[a] != b && mark[a] == 1)	ans++;
		arr[a] = b;
		mark[a] = 1;
	}

	cout << ans;

	return 0;
}
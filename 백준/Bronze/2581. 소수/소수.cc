#include <iostream>
#include <vector>

using namespace std;

int arr[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int M, N;
	int sum = 0;
	int min = 0;
	int mark = 0;
	cin >> M >> N;

	for (int i = 2; i <= N; i++) {
		arr[i] = i;
	}

	for (int i = 2; i * i <= N; i++) {
		if (arr[i] == 0)	continue;
		for (int j = 2 * i; j <= N; j += i) {
			arr[j] = 0;
		}
	}

	for (int i = M; i <= N; i++) {
		if (arr[i] != 0) {
			sum += i;
			if (mark == 0) {
				min = i;
				mark = 1;
			}
		}
	}

	if (sum == 0) {
		cout << -1;
	}
	else {
		cout << sum << '\n' << min;
	}

	return 0;
}
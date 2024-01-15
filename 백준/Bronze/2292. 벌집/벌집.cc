#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	int ans = 0;
	int num_limit = 1;

	cin >> N;

	while (num_limit < N) {
		num_limit += 6 * ans;
		ans++;
	}

	if (N != 1)	cout << ans;
	else {
		cout << "1";
	}

	return 0;
}
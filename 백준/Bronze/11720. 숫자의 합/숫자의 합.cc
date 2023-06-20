#include <iostream>

using namespace std;

int main() {
	int N;
	int sum = 0;

	cin >> N;
	while (N--) {
		int n;

		scanf("%1d", &n);
		sum += n;
	}

	cout << sum;

	return 0;
}
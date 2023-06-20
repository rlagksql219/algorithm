#include <iostream>

using namespace std;

int main() {
	int n;

	cin >> n;
	int length = 2 * n - 1;
	for (int i = 1; i < n; i++) {
		for (int j = n - i; j > 0; j--) {
			cout << " ";
		}

		int num = 2 * i - 1;
		for (int j = 0; j < num; j++) {
			if (j == 0 || j == num - 1) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << '\n';
	}

	for (int j = 0; j < 2 * n - 1; j++) {
		cout << "*";
	}

	return 0;
}
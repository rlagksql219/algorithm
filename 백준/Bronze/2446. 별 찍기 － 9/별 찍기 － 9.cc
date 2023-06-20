#include <iostream>

using namespace std;

int main() {
	int n;

	cin >> n;
	for (int i = n; i > 0; i--) {
		for (int j = 0; j < n - i; j++) {
			cout << " ";
		}

		int num = 2 * i - 1;
		for (int j = 0; j < num; j++) {
			cout << "*";
		}
		cout << '\n';
	}


	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < n - i; j++) {
			cout << " ";
		}

		int num = 2 * i - 1;
		for (int j = 0; j < num; j++) {
			cout << "*";
		}
		cout << '\n';
	}

	return 0;
}
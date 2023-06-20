#include <iostream>

using namespace std;

int main() {
	int n;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			cout << "*";
		}

		int num = 2 * n - 2 * i;
		for (int j = 0; j < num; j++) {
			cout << " ";
		}	
		
		for (int j = 0; j < i; j++) {
			cout << "*";
		}
		cout << '\n';
	}

	for (int i = n-1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			cout << "*";
		}

		int num = 2 * n - 2 * i;
		for (int j = 0; j < num; j++) {
			cout << " ";
		}

		for (int j = 0; j < i; j++) {
			cout << "*";
		}
		cout << '\n';
	}

	return 0;
}
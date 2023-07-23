#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	string ans;

	cin >> n;
	if (n == 0) {
		cout << 0;

		return 0;
	}

	while (n != 0) {
		if (n % -2 == 0) {
			ans.insert(0, "0");
			n /= -2;
		}
		else {
			ans.insert(0, "1");
			n--;
			n /= -2;
		}
	}

	cout << ans;

	return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	int n;
	long long ans = 0;

	cin >> str >> n;

	for (int i = 0; i < str.size(); i++) {
		int cnt = str.size() - i - 1;
		int tmp = 1;
		while (cnt--) {
			tmp *= n;
		}
		int tmp2 = str[i] - '0';
		if (tmp2 > 16)
			tmp2 -= 7;
		tmp *= tmp2;
		ans += tmp;
	}

	cout << ans;

	return 0;
}
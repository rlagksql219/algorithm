#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;

	cin >> str;
	int cnt = 3 - (str.length() % 3);
	while (cnt--) {
		str.insert(0, "0");
	}

	for (int i = 0; 3*i < str.length(); i++) {
		int tmp = 4;
		int num = 0;
		for (int j = 3*i; j < 3*(i+1); j++) {
			if (str[j] == '1') {
				num += tmp;
			}
			tmp /= 2;
		}
		if (i == 0 && num == 0 && str.length() > 3)	continue;
		cout << num;
	}

	return 0;
}
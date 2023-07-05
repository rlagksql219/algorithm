#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	string ans;

	getline(cin, str);

	for (int i = 0; i < str.size(); i++) {
		if ((int)str[i] >= 97 && (int)str[i] <= 122) {
			int tmp = str[i] + 13;
			if (tmp > 122)
				tmp -= 26;
			ans += (char)tmp;
		}
		else if ((int)str[i] >= 65 && (int)str[i] <= 90) {
			int tmp = str[i] + 13;
			if (tmp > 90)
				tmp -= 26;
			ans += (char)tmp;
		}
		else {
			ans += str[i];
		}
	}

	cout << ans;

	return 0;
}
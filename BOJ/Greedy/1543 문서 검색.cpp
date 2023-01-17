#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	string target;
	int ans = 0;

	getline(cin, s);
	getline(cin, target);

	for (int i = 0; i < s.length(); i++) {
		int mark = 0;
		if (s[i] == target[0]) {
			for (int j = 0; j < target.length(); j++) {
				if (i + target.length() > s.length()) {
					mark = 1;
					break;
				}
				if (s[i + j] != target[j]) {
					mark = 1;
					break;
				}
			}

			if (mark == 0) {
				ans++;
				i += target.length() - 1;
			}
		}
	}

	cout << ans;

	return 0;
}
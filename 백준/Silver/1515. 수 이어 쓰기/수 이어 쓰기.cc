#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num = 0;
	int ptr = 0;
	string str;
	cin >> str;
	while (num++ < 100000) {
		string s = to_string(num);
		for (int i = 0; i < s.length(); i++) {
			if (str[ptr] == s[i])	ptr++;
			if (ptr == str.length()) {
				cout << num;
				return 0;
			}
		}
	}

	return 0;
}

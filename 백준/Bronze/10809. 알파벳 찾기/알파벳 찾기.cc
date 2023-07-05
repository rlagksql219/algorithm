#include <iostream>
#include <string>

using namespace std;

int ascii[26];

int main() {
	string str;

	cin >> str;
	fill_n(ascii, 26, -1);
	for (int i = 0; i < str.size(); i++) {
		if (ascii[(int)str[i] - 97] == -1)
			ascii[(int)str[i] - 97] = i;
	}

	for (int i = 0; i < 26; i++)
		cout << ascii[i] << ' ';

	return 0;
}
#include <iostream>
#include <string>

using namespace std;

int ascii[26];

int main() {
	string str;

	cin >> str;
	for (int i = 0; i < str.size(); i++)
		ascii[(int)str[i] - 97]++;

	for (int i = 0; i < 26; i++)
		cout << ascii[i] << ' ';

	return 0;
}
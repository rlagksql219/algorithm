#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	int start = 0;

	cin >> str;
	while (str.substr(start, 10).size() >= 10) {
		cout << str.substr(start, 10) << '\n';
		start += 10;
	}

	cout << str.substr(start, 10);

	return 0;
}
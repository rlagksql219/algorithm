#include <iostream>
#include <string>

using namespace std;

int main() {
	long long input;
	int n;
	string str;
	
	cin >> input >> n;

	while (input != 0) {
		int tmp = input % n;
		if (tmp >= 10) {
			str += (char)((tmp + 7) + '0');
		}
		else {
			str += (char)(tmp + '0');
		}
		input /= n;
	}
	
	for (int i = str.size() - 1; i >= 0; i--) {
		cout << str[i];
	}

	return 0;
}
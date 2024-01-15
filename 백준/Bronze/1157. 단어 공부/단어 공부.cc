#include <iostream>
#include <vector>
#include <string>

using namespace std;

int arr[100];

int main() {
	string str;
	int max = 0, index = 0;

	cin >> str;
	for(int i = 0; i < str.length(); i++) {
		str[i] = toupper(str[i]);
		arr[(int)str[i]]++;
	}

	for (int i = 65; i <= 90; i++) {
		if (arr[i] > max) {
			max = arr[i];
			index = i;
		}
	}

	for (int i = index + 1; i <= 90; i++) {
		if (arr[i] == max) {
			cout << '?';
			return 0;
		}
	}

	cout << (char)index;

	return 0;
}
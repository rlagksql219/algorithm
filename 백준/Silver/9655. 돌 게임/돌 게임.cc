#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int mark = 0;

	cin >> N;
	
	while (N > 0) {
		if (N >= 3) {
			N -= 3;
			mark++;
		}
		else {
			N--;
			mark++;
		}
	}

	if (mark % 2 == 0) {
		cout << "CY" << '\n';
	}
	else {
		cout << "SK" << '\n';
	}

	return 0;
}
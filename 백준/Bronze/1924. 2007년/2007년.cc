#include <iostream>

using namespace std;

int main() {
	int x, y;
	int tmp = 0;

	cin >> x >> y;
	for (int i = 1; i < x; i++) {
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			tmp += 31;
		else if (i == 2)
			tmp += 28;
		else
			tmp += 30;
	}
	tmp += y;
	if (tmp % 7 == 0)
		cout << "SUN";
	else if (tmp % 7 == 1)
		cout << "MON";
	else if (tmp % 7 == 2)
		cout << "TUE";
	else if (tmp % 7 == 3)
		cout << "WED";
	else if (tmp % 7 == 4)
		cout << "THU";
	else if (tmp % 7 == 5)
		cout << "FRI";
	else if (tmp % 7 == 6)
		cout << "SAT";

	return 0;
}
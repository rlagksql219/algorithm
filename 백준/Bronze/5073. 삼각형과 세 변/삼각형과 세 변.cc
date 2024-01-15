#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {

	while (1) {
		int a, b, c;
		vector<int> v;
		string str;

		cin >> a >> b >> c;
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		if (a == 0 && b == 0 && c == 0)	break;

		sort(v.begin(), v.end());
		if (a == b && b == c && c == a)	str = "Equilateral";
		else if (v[0] == v[1] && v[0] != v[2])	str = "Isosceles";
		else if (v[1] == v[2] && v[0] != v[2])	str = "Isosceles";
		else {
			str = "Scalene";
		}

		if (v[0] + v[1] <= v[2])	str = "Invalid";

		cout << str << endl;
	}

	return 0;
}
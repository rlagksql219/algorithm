#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		string str;
		vector<int> v;
		string ans = " is acceptable.";

		cin >> str;
		if (str == "end")	break;

		for (int i = 0; i < str.length(); i++) {
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
				v.push_back(1);
			}
			else {
				v.push_back(2);
			}
		}

		if (find(v.begin(), v.end(), 1) == v.end()) {
			ans = " is not acceptable.";
		}

		for (int i = 0; i < str.size() - 2; i++) {
			if (str.size() < 3)	break;
			if (ans == " is not acceptable.")	break;

			if ((v[i] == v[i + 1]) && (v[i + 1] && v[i + 2]) && (v[i] == v[i + 2])) {
				ans = " is not acceptable.";
				break;
			}
		}

		for (int i = 0; i < str.size() - 1; i++) {
			if (str.size() < 2)	break;
			if (ans == " is not acceptable.")	break;

			if (str[i] == str[i + 1]) {
				if (str[i] == 'e' || str[i] == 'o')	continue;

				ans = " is not acceptable.";
				break;
				
			}
		}

		cout << "<" << str << ">" << ans << '\n';
	}

	return 0;
}
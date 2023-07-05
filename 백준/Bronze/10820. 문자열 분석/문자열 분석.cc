#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;

	while (getline(cin, str)) {
		if (str.size() == 0)	break;

		int cnt[4];
		fill_n(cnt, 4, 0);
		for (int i = 0; i < str.size(); i++) {
			if ((int)str[i] >= 97 && (int)str[i] <= 122)
				cnt[0]++;
			else if ((int)str[i] >= 65 && (int)str[i] <= 90)
				cnt[1]++;
			else if ((int)str[i] >= 48 && (int)str[i] <= 57)
				cnt[2]++;
			else if ((int)str[i] == 32)
				cnt[3]++;
		}

		for (int i = 0; i < 4; i++) {
			cout << cnt[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
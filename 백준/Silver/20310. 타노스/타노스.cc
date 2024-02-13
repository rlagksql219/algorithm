#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	int zero_cnt = 0;
	int one_cnt = 0;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0')	zero_cnt++;
	}
	one_cnt = s.length() - zero_cnt;
	zero_cnt /= 2;
	one_cnt /= 2;

	for (int i = 0; i < s.length(); i++) {
		if (one_cnt == 0)	break;
		if (s[i] == '1') {
			s.erase(s.begin() + i);
			one_cnt--;
			i--;
		}
	}
	for (int i = s.length()-1; i >= 0; i--) {
		if (zero_cnt == 0)	break;
		if (s[i] == '0') {
			s.erase(s.begin() + i);
			zero_cnt--;
			i++;
		}
	}

	cout << s;

	return 0;
}
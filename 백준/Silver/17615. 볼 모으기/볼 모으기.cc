#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	string str;
	int ans = 9999999;
	int red_cnt = 0, blue_cnt = 0;
	cin >> N >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'R')	red_cnt++;
		else
			blue_cnt++;
	}

	int tmp = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'R')	tmp++;
		else
			break;
	}
	ans = min(ans, red_cnt - tmp);

	tmp = 0;
	for (int i = str.length()-1; i >= 0; i--) {
		if (str[i] == 'R')	tmp++;
		else
			break;
	}
	ans = min(ans, red_cnt - tmp);

	tmp = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'B')	tmp++;
		else
			break;
	}
	ans = min(ans, blue_cnt - tmp);

	tmp = 0;
	for (int i = str.length() - 1; i >= 0; i--) {
		if (str[i] == 'B')	tmp++;
		else
			break;
	}
	ans = min(ans, blue_cnt - tmp);

	cout << ans;

	return 0;
}
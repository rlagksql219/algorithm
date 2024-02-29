#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a_cnt = 0;
	string str;
	cin >> str;
	int ans = str.length();
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'a')	a_cnt++;
	}

	for (int i = 0; i < str.length(); i++) {
		int b_cnt = 0;
		for (int j = i; j < i + a_cnt; j++) {
			int index = j % str.length();
			if (str[index] == 'b')	b_cnt++;
		}
		ans = min(ans, b_cnt);
	}

	cout << ans;

	return 0;
}
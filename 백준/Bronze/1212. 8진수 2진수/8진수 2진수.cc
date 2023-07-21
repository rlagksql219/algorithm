#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	string ans;

	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '0')
			ans += "000";
		else if (str[i] == '1')
			ans += "001";
		else if (str[i] == '2')
			ans +=  "010";
		else if (str[i] == '3')
			ans += "011";
		else if (str[i] == '4')
			ans += "100";
		else if (str[i] == '5')
			ans += "101";
		else if (str[i] == '6')
			ans += "110";
		else
			ans += "111";
	}

	while (!ans.empty()) {
		if (ans[0] == '1')	break;
		ans.erase(0, 1);
	}

	if (ans.empty())	ans += "0";
	cout << ans;

	return 0;
}
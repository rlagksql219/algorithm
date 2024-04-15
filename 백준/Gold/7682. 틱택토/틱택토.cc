#include <iostream>
#include <string>

using namespace std;

int test(string s, int num1, int num2) {
	int mark = 0;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i <= 2; i++) {
		char c = s[3 * i];
		if (c == '.')	continue;
		if (mark == 1)	continue;
		if (c == s[3 * i + 1] && c == s[3 * i + 2]) {
			if (c == 'O') { mark = 1; cnt1++; }
			else { mark = 2; cnt2++; }
		}
	}

	for (int i = 0; i <= 2; i++) {
		char c = s[i];
		if (c == '.')	continue;
		if (mark == 1)	continue;
		if (c == s[i + 3] && c == s[i + 6]) {
			if (c == 'O') { mark = 1; cnt1++; }
			else { mark = 2; cnt2++; }
		}
	}

	char c = s[4];
	if (c != '.' && mark == 0) {
		if (c == s[0] && c == s[8]) {
			if (c == 'O') { mark = 1; cnt1++; }
			else { mark = 2; cnt2++; }
		}
		if (c == s[2] && c == s[6]) {
			if (c == 'O') { mark = 1; cnt1++; }
			else { mark = 2; cnt2++; }
		}
	}

	if (mark == 2) { //X 승리
		if (cnt1 != 0)	mark = 0;
		if (num1 - num2 != 1)	mark = 0;
	}
	else if (mark == 1) { //O 승리
		if (cnt2 != 0)	mark = 0;
		if (num1 != num2)	mark = 0;

	}
	else { //비길때
		if (num1 == 5 && num2 == 4 && cnt1 == 0 && cnt2 == 0) { mark = 1; }
		else { mark = 0; }
	}

	return mark;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		string str;
		string ans = "";
		int mark = 0;
		cin >> str;

		if (str == "end")	break;

		int cnt_x = 0, cnt_o = 0;
		for (int i = 0; i <= 9; i++) {
			if (str[i] == 'X')	cnt_x++;
			if (str[i] == 'O')	cnt_o++;
		}

		if (cnt_x - cnt_o == 1 || cnt_x - cnt_o == 0) {
			mark = test(str, cnt_x, cnt_o);
			if (mark)	ans = "valid";
			else { ans = "invalid"; }
		}
		else {
			ans = "invalid";
		}

		cout << ans << '\n';
	}

	return 0;
}
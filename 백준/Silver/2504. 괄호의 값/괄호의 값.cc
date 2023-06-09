#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	string str;
	stack<char> s;
	int num = 1;
	int ans = 0;

	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			num *= 2;
			s.push(str[i]);
		}
		else if (str[i] == '[') {
			num *= 3;
			s.push(str[i]);
		}
		else if (str[i] == ')') {
			if (s.empty() || s.top() != '(') {
				cout << 0;
				return 0;
			}
			if (str[i - 1] == '(')
				ans += num;
			s.pop();
			num /= 2;
		}
		else {
			if (s.empty() || s.top() != '[') {
				cout << 0;
				return 0;
			}
			if (str[i - 1] == '[')
				ans += num;
			s.pop();
			num /= 3;
		}
	}

	if (s.empty())
		cout << ans;
	else
		cout << 0;


	return 0;
}
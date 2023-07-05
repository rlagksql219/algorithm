#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	string str;
	stack<char> s;
	int ans = 0;

	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(')
			s.push(str[i]);
		else {
			if (str[i - 1] == '(') { //레이저인 경우
				s.pop();
				ans += s.size();
			}
			else { //막대의 끝인 경우
				s.pop();
				ans++;
			}
		}
	}

	cout << ans;

	return 0;
}
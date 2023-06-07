#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	int T;

	cin >> T;
	while (T--) {
		string str;
		stack<char> s;
		int mark = 0;

		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(')
				s.push(str[i]);
			else {
				if (s.empty()) {
					cout << "NO" << '\n';
					mark = 1;
					break;
				}
				else
					s.pop();
			}
		}

		if (s.empty()) {
			if(mark == 0)
				cout << "YES" << '\n';
		}
		else
			cout << "NO" << '\n';
	}

	return 0;
}
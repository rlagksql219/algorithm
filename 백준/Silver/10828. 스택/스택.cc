#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	int n;
	int result = 0;
	string cmd;
	int num;
	stack<int> s;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cmd;

		if (cmd == "pop") {
			if (s.size() == 0) {
				result = -1;
				cout << -1 << '\n';
			}
			else {
				result = s.top();
				cout << result << '\n';
				s.pop();
			}
		}
		else if (cmd == "size") {
			cout << s.size() << '\n';
		}
		else if (cmd == "empty") {
			if (s.size() == 0) {
				result = 1;
				cout << result << '\n';
			}
			else {
				result = 0;
				cout << result << '\n';
			}
		}
		else if (cmd == "top") {
			if (s.size() == 0) {
				result = -1;
				cout << result << '\n';
			}
			else {
				result = s.top();
				cout << result << '\n';
			}
		}
		else if (cmd == "push") {
			cin >> num;
			s.push(num);
		}
	}

	return 0;
}
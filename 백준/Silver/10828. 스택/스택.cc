#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	int n;
	stack<int> s;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string cmd;
		cin >> cmd;

		if (cmd == "pop") {
			if (s.size() == 0)
				cout << -1 << '\n';
			else {
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else if (cmd == "size")
			cout << s.size() << '\n';
		else if (cmd == "empty") {
			if (s.size() == 0) 
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (cmd == "top") {
			if (s.size() == 0) 
				cout << -1 << '\n';
			else
				cout << s.top() << '\n';
		}
		else if (cmd == "push") {
			int num;
			cin >> num;
			s.push(num);
		}
	}

	return 0;
}
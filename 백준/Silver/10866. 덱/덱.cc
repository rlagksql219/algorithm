#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
	int n;
	deque<int> dq;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string cmd;

		cin >> cmd;
		if (cmd == "push_front") {
			int num;
			cin >> num;
			dq.push_front(num);
		}
		else if (cmd == "push_back") {
			int num;
			cin >> num;
			dq.push_back(num);
		}
		else if (cmd == "pop_front") {
			if (dq.empty())
				cout << "-1" << '\n';
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (cmd == "pop_back") {
			if (dq.empty())
				cout << "-1" << '\n';
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (cmd == "size") {
			cout << dq.size() << '\n';
		}
		else if (cmd == "empty") {
			if (dq.empty())
				cout << "1" << '\n';
			else
				cout << 0 << '\n';
		}
		else if (cmd == "front") {
			if (dq.empty())
				cout << "-1" << '\n';
			else {
				cout << dq.front() << '\n';
			}
		}
		else if (cmd == "back") {
			if (dq.empty())
				cout << "-1" << '\n';
			else {
				cout << dq.back() << '\n';
			}
		}
	}

	return 0;
}
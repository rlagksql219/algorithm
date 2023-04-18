#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
	int n;
	queue<int> q;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string cmd;
		cin >> cmd;

		if (cmd == "pop") {
			if (q.size() == 0)
				cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (cmd == "size")
			cout << q.size() << '\n';
		else if (cmd == "empty") {
			if (q.size() == 0)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (cmd == "front") {
			if (q.size() == 0)
				cout << -1 << '\n';
			else
				cout << q.front() << '\n';
		}
		else if (cmd == "back") {
			if (q.size() == 0)
				cout << -1 << '\n';
			else
				cout << q.back() << '\n';
		}
		else if (cmd == "push") {
			int num;
			cin >> num;
			q.push(num);
		}
	}

	return 0;
}
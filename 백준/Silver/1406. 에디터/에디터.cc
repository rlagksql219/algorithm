#include <string>
#include <iostream>
#include <list>

using namespace std;

int main() {
	string str;
	int n;

	cin >> str >> n;
	list<char> l(str.begin(), str.end());
	auto cursor = l.end();
	for (int i = 0; i < n; i++) {
		char tmp;
		cin >> tmp;

		if (tmp == 'L') {
			if (cursor != l.begin())
				cursor--;
		}
		else if (tmp == 'D') {
			if (cursor != l.end())
				cursor++;
		}
		else if (tmp == 'B') {
			if (cursor != l.begin()) {
				cursor = l.erase(--cursor);
			}
		}
		else {
			char insert_tmp;
			cin >> insert_tmp;
			l.insert(cursor, insert_tmp);
		}
	}

	for (auto iter = l.begin(); iter != l.end(); iter++)
		cout << *iter;

	return 0;
}

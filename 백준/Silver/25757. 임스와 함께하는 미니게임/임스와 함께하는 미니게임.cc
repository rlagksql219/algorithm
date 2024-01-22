#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	char game;
	set<string> s;

	cin >> N >> game;

	for (int i = 0; i < N; i++) {
		string str;

		cin >> str;
		s.insert(str);
	}

	if (game == 'Y')
		cout << s.size();
	else if (game == 'F')
		cout << s.size() / 2;
	else
		cout << s.size() / 3;

	return 0;
}
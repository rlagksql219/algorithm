#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;
	set<string> ans;

	for (int i = 0; i < str.length(); i++) {
		string s = "";
		for (int j = i; j < str.length(); j++) {
			s += str[j];
			ans.insert(s);
		}
	}

	cout << ans.size();

	return 0;
}
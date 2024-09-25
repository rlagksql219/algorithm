#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s, p;
	int ans = 0;
	cin >> s >> p;

	if (strstr(s.c_str(), p.c_str()) != NULL)	ans = 1;
	cout << ans;

	return 0;
}
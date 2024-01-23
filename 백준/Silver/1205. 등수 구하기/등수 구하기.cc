#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, score, P;
	vector<int> v;
	int ans = 0;
	int mark = 0;

	cin >> N >> score >> P;
	for (int i = 0; i < N; i++) {
		int tmp;

		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end(), greater<>());

	if (N == 0)	ans = 1;
	for (int i = 0; i < N; i++) {
		if (score >= v[i]) {
			ans = i + 1;
			mark = 1;
			break;
		}
	}
	if (N < P && mark == 0)	ans = N + 1;
	if (N == P && score <= v.back())	ans = -1;

	cout << ans;

	return 0;
}
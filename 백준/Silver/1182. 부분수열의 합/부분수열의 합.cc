#include <iostream>
#include <vector>

using namespace std;

int N, S;
vector<int> v;
int ans;

void dfs(int i, int sum) {
	if (i == N)	return;
	if (sum + v[i] == S)	ans++;

	dfs(i + 1, sum);
	dfs(i + 1, sum + v[i]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	dfs(0, 0);

	cout << ans;

	return 0;
}
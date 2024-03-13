#include <iostream>
#include <vector>

using namespace std;

vector<int> v[200001];
bool visited[200001];

long long dfs(int node) {
	long long cnt = 1;
	for (int i = 0; i < v[node].size(); i++) {
		int next = v[node][i];
		if (visited[next]) continue;
		visited[next] = 1;
		cnt += dfs(next);
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	long long ans = 1;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i])	continue;
		visited[i] = true;
		ans = (ans * dfs(i)) % 1000000007;
	}

	cout << ans;

	return 0;
}
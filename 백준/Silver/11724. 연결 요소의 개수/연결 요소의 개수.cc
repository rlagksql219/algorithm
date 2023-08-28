#include <iostream>
#include <vector>

using namespace std;

vector<int> v[1001];
bool visited[1001];

void dfs(int node) {
	visited[node] = true;

	for (int i = 0; i < v[node].size(); i++) {
		if (!visited[v[node][i]]) {
			dfs(v[node][i]);
		}
	}
}

int main() {
	int n, m;
	int ans = 0;
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int tmp1, tmp2;

		cin >> tmp1 >> tmp2;
		v[tmp2].push_back(tmp1);
		v[tmp1].push_back(tmp2);
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
			ans++;
		}
	}

	cout << ans;

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[100001];
bool visited[100001];
int parent[100001];

void dfs(int node) {
	visited[node] = true;
	
	for (int i = 0; i < v[node].size(); i++) {
		int child = v[node][i];

		if (!visited[child]) {
			parent[child] = node;
			dfs(child);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		int a, b;

		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	parent[1] = 1;
	dfs(1);

	for (int i = 2; i <= N; i++)
		cout << parent[i] << '\n';

	return 0;
}
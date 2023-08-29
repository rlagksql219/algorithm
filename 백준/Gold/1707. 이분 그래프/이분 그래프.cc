#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

vector<int> v[20001];
bool visited[20001];
int checked[20001];
int flag;

void dfs(int node, int flag) {
	visited[node] = true;
	if (flag == 1) {
		checked[node] = -1;
		flag = 0;
	}
	else {
		checked[node] = 1;
		flag = 1;
	}

	for (int i = 0; i < v[node].size(); i++) {
		if (!visited[v[node][i]]) {
			dfs(v[node][i], flag);
		}
	}
}

int main() {
	int k;

	cin >> k;
	while (k--) {
		int n, m;
		string ans = "YES";

		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int tmp1, tmp2;

			cin >> tmp1 >> tmp2;
			v[tmp2].push_back(tmp1);
			v[tmp1].push_back(tmp2);
		}

		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				dfs(i, flag);
			}
		}

		for (int i = 1; i <= n; i++) {
			int target = checked[i];

			for (int j = 0; j < v[i].size(); j++) {
				if (target == checked[v[i][j]]) {
					ans = "NO";
				}
			}
		}

		cout << ans << "\n";


		//전역변수 초기화
		for (int i = 0; i <= n; i++) {
			v[i].clear();
		}
		memset(visited, 0, sizeof(visited));
		memset(checked, 0, sizeof(checked));
		flag = 0;
	}

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int Find(int x) {
	if (parent[x] == x)	return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	int x = Find(a); //root 찾기
	int y = Find(b);
	
	if (x < y)	parent[y] = x;
	else {
		parent[x] = y;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		parent.push_back(i);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int tmp;
			cin >> tmp;
			if (tmp) {
				Union(i, j);
			}
		}
	}

	int root;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		if (i == 0)	root = Find(tmp);
		else {
			if (Find(root) != Find(tmp)) {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";

	return 0;
}
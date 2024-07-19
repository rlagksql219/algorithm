#include <iostream>
#include <vector>

using namespace std;

int parent[51];
vector<int> truth;
vector<int> people[51];


int Find(int x) {
	if (parent[x] == x)	return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	int x = Find(a);
	int y = Find(b);

	if (x < y)	parent[y] = x;
	else {
		parent[x] = y;
	}
}

bool isUnion(int a, int b) {
	int x = Find(a);
	int y = Find(b);
	if (x == y)	return true;
	else {
		return false;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, a, b;
	cin >> N >> M;
	cin >> a;
	int ans = M;

	for (int i = 0; i < a; i++) {
		cin >> b;
		truth.push_back(b);
	}

	for (int i = 0; i < M; i++) {
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> b;
			people[i].push_back(b);
		}
	}

	//parent 배열 초기화
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		a = people[i][0];
		for (int j = 1; j < people[i].size(); j++) {
			b = people[i][j];
			Union(a, b);
		}
	}

	for (int i = 0; i < M; i++) {
		bool check = true;
		for (int j = 0; j < people[i].size(); j++) {
			if (!check)	break;
			a = people[i][j];
			
			for (int k = 0; k < truth.size(); k++) {
				b = truth[k];
				if (isUnion(a, b)) {
					check = false;
					break;
				}
			}
		}
		if (!check)	ans--;
	}

	cout << ans;

}
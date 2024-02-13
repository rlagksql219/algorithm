#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n, k, t, m;
		cin >> n >> k >> t >> m;
		int arr[101][101] = { 0 };
		int cnt[101] = { 0 };
		int order[101] = { 0 };
		t--;
		for (int i = 0; i < m; i++) {
			int id, num, s;
			cin >> id >> num >> s;
			id--;
			num--;
			arr[id][num] = max(arr[id][num], s);
			cnt[id]++;
			order[id] = i;
		}


		vector < pair<int, pair<int, pair<int, int>>>> v; //총점, 제출횟수, 최종제출시간, 팀번호
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = 0; j < k; j++)
				sum += arr[i][j];
			v.push_back({ sum,{-cnt[i],{-order[i],i}} });
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < n; i++) {
			if (v[i].second.second.second == t) printf("%d\n", n - i);
		}
	}

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v;
	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	
	cin >> M;
	for (int i = 0; i < M; i++) {
		int tmp;
		cin >> tmp;
	
		//binary search
		int start = 0;
		int end = N-1;
		int ans = 0;
		
		while (start <= end) {
			int mid = (start + end) / 2;

			if (tmp > v[mid]) {
				start = mid + 1;
			}
			else if(tmp < v[mid]) {
				end = mid - 1;
			}
			else {
				ans = 1;
				break;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
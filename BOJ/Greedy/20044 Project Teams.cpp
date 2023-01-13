#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
if 조건 귀찮아서 min을 적당히 큰 값으로 초기화하고 풀었는데 그것 때문에 오답처리 됨..
꾀부리지 말고 정확하게 풀이하자 !!
*/

int main() {
	int n;
	vector<int> v;
	int ans = 0;

	cin >> n;
	for (int i = 0; i < 2 * n; i++) {
		int tmp;

		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		int min = 0;

		min += v[i];
		min += v[2 * n - 1 - i];
		
		if (i == 0) {
			ans = min;
		}

		if (min < ans) {
			ans = min;
		}
	}

	cout << ans;

	return 0;
}
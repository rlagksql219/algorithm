#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> v(N);
	vector<int> ans(2);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end()); //양쪽 끝에서 포인터 이동하는 경우는 정렬 해주기!


	/* 투포인터 알고리즘 */
	int start = 0, end = N-1, min = 2000000000;
	while (start < end) {
		int sum = v[start] + v[end];

		if (min > abs(sum)) {
			min = abs(sum);
			ans[0] = v[start];
			ans[1] = v[end];
		}

		if (sum < 0)	start++;
		else end--;
	}

	sort(ans.begin(), ans.end());
	cout << ans[0] << " " << ans[1];

	return 0;
}
#include <vector>
#include <iostream>

using namespace std;

int main() {
	int N, S;
	cin >> N >> S;
	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	/* 투포인터 알고리즘 */
	int start = 0, end = 0, sum = 0, ans = 2 * N;
	while (start <= end) {
		if (sum < S) {
			if (end >= N)	break;
			
			sum += v[end];
			end++;
		}
		else {
			if (start >= N)	break;
			
			int length = end - start + 1;
			if (length < ans)	ans = length;
			sum -= v[start];
			start++;
		}

	}

	if (ans == 2 * N)	ans = 0;
	else ans--;

	cout << ans << endl;

	return 0;
}
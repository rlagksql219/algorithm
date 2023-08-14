#include <iostream>
#include <vector>

using namespace std;

int main() {
	int A, B, N;
	vector<int> v;
	int num = 0;
	vector<int> ans;

	cin >> A >> B >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		
		cin >> tmp;
		v.push_back(tmp);
	}

	for (int i = N - 1; i >= 0; i--) {
		int cnt = N - 1 - i;
		int mul = 1;
		while (cnt--) {
			mul *= A;
		}

		num += v[i] * mul;
	}

	while (num > 0) {
		ans.push_back(num % B);
		num /= B;
	}

	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << " ";
	}

	return 0;
}
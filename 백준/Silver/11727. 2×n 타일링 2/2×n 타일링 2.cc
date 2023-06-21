#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	vector<int> v;

	cin >> N;
	v.push_back(0);
	v.push_back(1);
	v.push_back(3);
	for (int i = 3; i <= N; i++) {
		int tmp = (v[i - 1] + 2 * v[i - 2]) % 10007;
		v.push_back(tmp);
	}

	cout << v[N];

	return 0;
}
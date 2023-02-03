#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	vector<long long> v; // int 범위 주의 ㅜㅜ

	cin >> n;
	v.push_back(0);
	v.push_back(1);
	for (int i = 2; i <= n; i++) {
		long long tmp = v[i - 1] + v[i - 2];
		v.push_back(tmp);
	}

	cout << v[n];

	return 0;
}
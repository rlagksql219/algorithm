#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
if ���� �����Ƽ� min�� ������ ū ������ �ʱ�ȭ�ϰ� Ǯ���µ� �װ� ������ ����ó�� ��..
�Һθ��� ���� ��Ȯ�ϰ� Ǯ������ !!
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
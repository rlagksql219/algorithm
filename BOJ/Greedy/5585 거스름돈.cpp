#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int n, money;
	int choice[6] = { 500,100,50,10,5,1 };
	int ans = 0;

	cin >> n;
	money = 1000 - n;

	while (money > 0) {
		for (int i = 0; i < 6; i++) {
			if (money >= choice[i]) {
				money -= choice[i];
				ans++;
				break;
			}
		}
	}

	cout << ans;

	return 0;
}
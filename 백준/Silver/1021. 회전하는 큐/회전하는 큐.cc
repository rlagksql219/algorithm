#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main() {

	int n, m;
	deque<int> dq;
	int ans = 0;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		dq.push_back(i);

	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;

		if (dq.front() == tmp)
			dq.pop_front();
		else {
			int f = find(dq.begin(), dq.end(), tmp) - dq.begin();
			int b = dq.size() - (find(dq.begin(), dq.end(), tmp) - dq.begin()) -1;
			
			if (f <= b) { // 2번 연산
				while (dq.front() != tmp) {
					int num = dq.front();
					dq.pop_front();
					dq.push_back(num);
					ans++;
				}
			}
			else { // 3번 연산
				while (dq.front() != tmp) {
					int num = dq.back();
					dq.pop_back();
					dq.push_front(num);
					ans++;
				}
			}
			dq.pop_front();
		}
	}

	cout << ans;

	return 0;
}
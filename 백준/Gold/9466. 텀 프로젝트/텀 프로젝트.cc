#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int arr[100001];
bool check[100001];
bool done[100001];
int cnt;

void dfs(int node) {
	check[node] = true;

	int next = arr[node];

	if (!check[next]) {
		dfs(next);
	}
	else if (!done[next]) { //방문은 했지만, 팀 매칭이 완료되지 않은 경우
		for (int i = next; i != node; i = arr[i]) { //사이클에 속한 인원 확인
			cnt++;
		}
		cnt++; //사이클 시작 학생 추가
	}

	done[node] = true; //팀 매칭 완료
}

int main() {
	int T;

	cin >> T;
	while (T--) {
		int n;

		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}

		for (int i = 1; i <= n; i++) {
			if (!check[i]) {
				dfs(i);
			}
		}

		cout << n - cnt << '\n';

		//초기화
		cnt = 0;
		memset(arr, 0, sizeof(arr));
		memset(check, false, sizeof(check));
		memset(done, false, sizeof(done));
		
	}

	return 0;
}
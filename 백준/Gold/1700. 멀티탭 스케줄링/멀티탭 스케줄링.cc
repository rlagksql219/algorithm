#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;
	vector<int> order(K);
	for (int i = 0; i < K; i++) {
		cin >> order[i];
	}

	set<int> multitap;
	int ans = 0;

	for (int i = 0; i < K; i++) {
		int device = order[i];

		if (multitap.find(device) != multitap.end())	continue; //이미 꽂혀 있는 경우

		if (multitap.size() < N) { //멀티탭에 자리가 있는 경우
			multitap.insert(device);
			continue;
		}


		//자리가 없는 경우, 뭐를 뺄지 정해야 함
		/*
		1. 앞으로 사용하지 않는 기기
		2. 젤 마지막에 사용하는 기기

		가장 나중에 사용하는 기기를 찾기
		초기값을 K로 초기화 -> 앞으로 사용하지 않는다면 젤 큰 값이라 우선적으로 뽑아야되는 기기로 선정됨
		*/
		int unplug = -1;
		int last_time = -1;

		for (int plug : multitap) {
			int last_use = K;
			for (int j = i + 1; j < K; j++) {
				if (order[j] == plug) {
					last_use = j;
					break;
				}
			}

			if (last_use > last_time) {
				last_time = last_use;
				unplug = plug;
			}
		}

		multitap.erase(unplug);
		multitap.insert(device);
		ans++;
	}

	cout << ans;

	return 0;
}
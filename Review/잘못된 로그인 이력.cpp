#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>

using namespace std;

/*
사용된 알고리즘
1. 문자열 토큰 분리
2. tuple 정렬
3. tuple 자료구조 이용해서 조건 비교
*/

vector<string> split(string s, string target) {
	vector<string> v;
	int start = 0;
	int t = s.find(target);

	while (t != string::npos) {
		v.push_back(s.substr(start, t - start));
		start = t + 1;
		t = s.find(target, start);
	}
	v.push_back(s.substr(start, s.size() - start));

	return v;
}

bool compare(tuple<string, string, string> t1, tuple<string, string, string> t2) {
	return get<1>(t1) < get<1>(t2);
}

int main() {
	int N;
	vector<tuple<string, string, string>> log;
	vector<string> list;
	int ans = 0;
	string name;
	
	cin >> N;
	cin.ignore();
	while (N--) {
		string str;
		vector<string> v;
		string name, time, inout;
		tuple<string, string, string> t;

		getline(cin, str);
		v = split(str, " ");
		name = v[0];
		time = v[1];
		inout = v[2];

		t =make_tuple(name, time, inout);
		log.push_back(t);

		if(find(list.begin(), list.end(), name) == list.end())
			list.push_back(name);
	}

	sort(log.begin(), log.end(), compare);


	for (int i = 0; i < log.size(); i++) {
		int mark = 0;
		if (find(list.begin(), list.end(), get<0>(log[i])) == list.end())
			break;

		for (int j = i+1; j < log.size(); j++) {
			if (get<0>(log[i]) == get<0>(log[j])) {
				mark = 1;
				list.erase(find(list.begin(), list.end(), get<0>(log[i])));

				if (get<2>(log[i]) != "IN") {
					ans++;
					break;
				}
				if (get<2>(log[j]) != "OUT") {
					ans++;
					break;
				}
			}
		}

		if (mark == 0) { //IN or OUT 없음
			ans++;
		}
	}


	cout << ans;

	return 0;
}
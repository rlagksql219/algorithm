#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int compare(const pair<int, string>& a, const pair<int, string>& b) {
	return a.first < b.first;
}

int main() {
	int N;
	vector<pair<int, string>> v;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int age;
		string name;
		cin >> age >> name;
		v.push_back({ age, name });
	}

	stable_sort(v.begin(), v.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << v[i].first << " " << v[i].second << '\n';
	}

	return 0;
}
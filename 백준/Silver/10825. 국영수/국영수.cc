#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct student {
	int kor;
	int eng;
	int math;
	string name;
};

bool compare(const student& a, const student& b) {
	if (a.kor != b.kor) {
		return a.kor > b.kor;
	}
	else {
		if (a.eng != b.eng) {
			return a.eng < b.eng;
		}
		else {
			if (a.math != b.math) {
				return a.math > b.math;
			}
			else {
				return a.name < b.name;
			}
		}
	}
}

int main() {
	int N;
	cin >> N;
	vector<student> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << v[i].name << '\n';
	}

	return 0;
}
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B;
    int answer = 0;
    cin >> A >> B;
    answer = A-B;
    cout << answer;
	
	return 0;
}
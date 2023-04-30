#include <iostream>
using namespace std;

int a[11], ans[11];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (cnt == a[i] && ans[j] == 0) {
                ans[j] = i;
                break;
            }
            if (ans[j] == 0) cnt++;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}
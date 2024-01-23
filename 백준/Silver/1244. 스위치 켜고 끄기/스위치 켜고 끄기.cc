#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int what, num;
        cin >> what >> num;

        if (what == 1) { // 남
            for (int j = num - 1; j < N; j += num) {
                arr[j] = !arr[j];
            }
        } else { // 여
            int left = num - 2;
            int right = num;
            while (left >= 0 && right < N && arr[left] == arr[right]) {
                arr[left] = !arr[left];
                arr[right] = !arr[right];
                left--;
                right++;
            }
            arr[num - 1] = !arr[num - 1];
        }
    }

    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
        
        // 20개를 출력한 후 개행 추가
        if ((i + 1) % 20 == 0) {
            cout << "\n";
        }
    }

    return 0;
}

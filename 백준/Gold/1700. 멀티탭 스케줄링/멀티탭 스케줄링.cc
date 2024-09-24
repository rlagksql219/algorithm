#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> schedule(K);
    for (int i = 0; i < K; i++) {
        cin >> schedule[i];
    }
    
    set<int> multitap;  // 현재 멀티탭에 꽂혀있는 기기들
    int unplug_count = 0;
    
    for (int i = 0; i < K; i++) {
        int device = schedule[i];
        
        // 이미 꽂혀 있는 경우
        if (multitap.find(device) != multitap.end()) {
            continue;
        }
        
        // 멀티탭에 자리가 있는 경우
        if (multitap.size() < N) {
            multitap.insert(device);
            continue;
        }
        
        // 자리가 없으니 플러그를 빼야 함
        int to_unplug = -1;
        int farthest = -1;
        
        for (int plugged : multitap) {
            int last_use = K;
            for (int j = i + 1; j < K; j++) {
                if (schedule[j] == plugged) {
                    last_use = j;
                    break;
                }
            }
            if (last_use > farthest) {
                farthest = last_use;
                to_unplug = plugged;
            }
        }
        
        // 멀티탭에서 가장 나중에 사용될 기기를 빼고 새로운 기기를 꽂음
        multitap.erase(to_unplug);
        multitap.insert(device);
        unplug_count++;
    }
    
    cout << unplug_count << endl;
    return 0;
}
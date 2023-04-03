#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    vector<int> cnt(number, 0);
    
    for(int i=1; i<=number; i++) {
        for(int j=1; j*j<=i; j++) {
            if(j*j == i)   cnt[i-1]++;
            else if(i%j == 0)   cnt[i-1] += 2;
        }
    }
    
    for(int i=0; i<number; i++) {
        if(cnt[i] <= limit) answer += cnt[i];
        else answer += power;
    }
    
    return answer;
}
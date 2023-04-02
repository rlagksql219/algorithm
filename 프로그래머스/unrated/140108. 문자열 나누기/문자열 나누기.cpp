#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    for(int i=0; i<s.size(); i++) {
        int cnt1=0, cnt2=0;
        char x = s[i]; cnt1++;
        if(i == s.size()-1) {
            answer++;
            break;
        }
        for(int j=i+1; j<s.size(); j++) {
            if(s[j] == x)   cnt1++;
            else cnt2++;
    
            if(cnt1 == cnt2) {
                answer++;
                i = j;
                break;
            }
            
            if(j == s.size()-1) {
                answer++;
                return answer;
            }
        }
    }
    
    return answer;
}
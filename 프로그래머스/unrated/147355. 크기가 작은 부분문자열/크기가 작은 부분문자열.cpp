#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int iter = t.length() - (p.length() - 1);
    long long num = 0;
    
    for(int i=0; i<iter; i++) {
        string tmp = t.substr(i, p.size());
        num = stoll(tmp);
        if(stoll(p) >= num)
            answer++;
    }
    
    return answer;
}
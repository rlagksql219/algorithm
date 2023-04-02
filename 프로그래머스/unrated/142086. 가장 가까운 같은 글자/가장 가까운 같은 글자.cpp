#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    for(int i=0; i<s.size(); i++) {
        char c = s[i];
        int mark = 0;
        
        for(int j=i-1; j>=0; j--) {
            if(s[j] == c) {
                answer.push_back(i-j);
                mark = 1;
                break;
            }
        }
        if(mark == 0)
            answer.push_back(-1);
    }
    
    return answer;
}
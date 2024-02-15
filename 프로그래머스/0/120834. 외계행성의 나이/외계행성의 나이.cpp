#include <string>
#include <vector>

using namespace std;

string solution(int age) {
    string answer = "";
    string s = to_string(age);
    
    for(int i=0; i<s.size(); i++) {
        answer += s[i] + '0' + 1;
    }
    
    return answer;
}
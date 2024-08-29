#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    int answer = -1;
    string str = to_string(num);
    char target = k + '0';
    
    for(int i=0; i<str.length(); i++) {
        char c = str[i];
        if(c == target) {
            answer = i + 1;
            break;
        }
    }
    
    return answer;
}
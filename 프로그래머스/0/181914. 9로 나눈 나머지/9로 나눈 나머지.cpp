#include <string>
#include <vector>

using namespace std;

int solution(string number) {
    int answer = 0;
    
    for(int i=0; i<number.length(); i++) {
        answer += int(number[i]) - 48;
    }
    
    answer %= 9;
    
    return answer;
}
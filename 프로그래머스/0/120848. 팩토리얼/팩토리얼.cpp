#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int sum = 1;
    int answer = 0;
    
    for(int i=1;; i++) {
        sum *= i;
        if(sum > n) {
            answer = i;
            break;
        }
    }
    
    answer--;
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int solution(int order) {
    int answer = 0;
    
    while(order != 0) {
        int num = order % 10;
        order /= 10;
        
        if(num == 3 || num == 6 || num == 9)  answer++;
    }
    
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, bool flag) {
    int answer = a - b;
    
    if(flag)    answer = a + b;
    
    return answer;
}
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int hp) {
    int answer = 0;
    int num1=0, num2=0;
    
    num1 = hp/5;
    hp -= num1*5;
    num2 = hp/3;
    hp -= num2*3;
    answer += num1;
    answer += num2;
    answer += hp;
    
    return answer;
}
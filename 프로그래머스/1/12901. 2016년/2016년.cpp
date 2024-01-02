#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int tmp = 0;
    int month[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string day[7] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};    
    
    for(int i=1; i<a; i++) {
        tmp += month[i];
    }
    
    tmp += (b-1);
    answer = day[tmp % 7];
    
    return answer;
}
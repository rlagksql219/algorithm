#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    for(int i=0; i<my_string.length(); i++) {
        if(my_string[i] == 'a') continue;
        if(my_string[i] == 'e') continue;
        if(my_string[i] == 'i') continue;
        if(my_string[i] == 'o') continue;
        if(my_string[i] == 'u') continue;
        
        answer += my_string[i];
    }
    
    return answer;
}
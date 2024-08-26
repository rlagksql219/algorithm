#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string n_str) {
    string answer = "";
    
    int index = 0;
    if(n_str[0] == '0') {
        index++;
        while(1) {
            if(n_str[index] != '0') break;
            index++;
        }
    }
    
    for(int i=index; i<n_str.length(); i++) {
        answer += n_str[i];
    }
    
    return answer;
}
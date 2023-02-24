#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    int mark = 0;
    int d = 0;
    int r = 0;
    int size = common.size();
    
    for(int i=0; i<common.size(); i++) {
        if(common[i] == 0)
            mark = 1;
    }
    
    if((common[2] - common[1]) == (common[1] - common[0]))
        d = common[1] - common[0];
    
    if(mark != 1) {
        if((common[2] / common[1]) == (common[1] / common[0])) {
            r = common[1] / common[0]; 
        }
    }
    
    
    if(d != 0) 
        answer = common[size - 1] + d;
    
    if(r != 0) 
        answer = common[size - 1] * r;

    
    return answer;
}
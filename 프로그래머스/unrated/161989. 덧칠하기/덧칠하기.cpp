#include <string>
#include <vector>

using namespace std;

int tile[100000];

int solution(int n, int m, vector<int> section) {
    int answer = 0;
   
    for(int i=0; i<section.size(); i++) {
        tile[section[i]] = 1;
    }
    
    
    for(int i=1; i<=n; i++) {
        if(tile[i] == 1) {
            for(int j=0; j<m; j++) {
                if(i+j > n) break;
                tile[i+j] = 0;
            }
            answer++;
        }
    }
    
    return answer;
}
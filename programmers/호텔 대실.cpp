#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
https://velog.io/@rlagksql219/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4C-%ED%98%B8%ED%85%94-%EB%8C%80%EC%8B%A4
*/

int arr[25][61];

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    for(int i=0; i<book_time.size(); i++) {
        int sh = stoi(book_time[i][0].substr(0, 2));
        int sm = stoi(book_time[i][0].substr(3, 2));
        int fh = stoi(book_time[i][1].substr(0, 2));
        int fm = stoi(book_time[i][1].substr(3, 2));
        fm += 10;
        
        if(fm > 59) {
            fh++;
            fm -= 60;
        }
        
        for(int j=sh; j<=fh; j++) {
            for(int k=0; k<60; k++) {
                if(j == sh) {
                    if(k < sm)
                        continue;
                    
                }
                if(j == fh) {
                    if(k >= fm)
                        break;
                    
                }
                arr[j][k]++;
            }
        }
    }
    
    for(int i=0; i<24; i++) {
        for(int j=0; j<60; j++) {
            if(arr[i][j] > answer)
                answer = arr[i][j];
        }
    }
    
    return answer;
}
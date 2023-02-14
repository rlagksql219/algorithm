#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

/*
https://velog.io/@rlagksql219/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4C-%EA%B0%9C%EC%9D%B8%EC%A0%95%EB%B3%B4-%EC%88%98%EC%A7%91-%EC%9C%A0%ED%9A%A8%EA%B8%B0%EA%B0%84
*/

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> map;
    
    int year = stoi(today.substr(0, 4));
    int month = stoi(today.substr(5, 2));
    int day = stoi(today.substr(8, 2));
    int total = year * 12 * 28 + (month - 1) * 28 + day;
    
    for(int i=0; i<terms.size(); i++) {
        char c;
        int num;
        stringstream ss(terms[i]);
        ss >> c >> num;
        map[c] = num;
    }
    
    for(int i=0; i<privacies.size(); i++) {
        int y = stoi(privacies[i].substr(0, 4));
        int m = stoi(privacies[i].substr(5, 2));
        int d = stoi(privacies[i].substr(8, 2));
        char matching = privacies[i].back();
        m += map[matching];
        
        int tmp = y * 12 * 28 + (m - 1) * 28 + d - 1; // 문제에 의하면 2021.01.05 & 12달인 경우, 2022.01.04까지니까 날짜에서 -1 해야 함!
        
        if(total > tmp) // 오늘 날짜 기준으로 그거보다 작은 거 전부 폐기
            answer.push_back(i+1);
    }
    
    return answer;
}
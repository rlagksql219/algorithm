#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
https://school.programmers.co.kr/learn/courses/30/lessons/155652?language=cpp

문자열 인덱스 문제!
반복문으로 조건 비교해가며 인덱스를 더해주는 방식으로 구현했는데 자꾸 시간초과 났다.
skip 할 알파벳 제외하고 list 만들고, find 함수로 위치 구해서 바로 index 더해줘야 시간초과 없이 풀이 가능
*/

string solution(string s, string skip, int index) {
    string answer = s;
    string list = "";
    char c = 'a';
    
    for(int i=0; i<26; i++) {
        if(skip.find(c) == string::npos)
            list.push_back(c);
        c++;
    }

   for(int i=0; i<s.length(); i++) {
      int pos = list.find(answer[i]) + index;
      pos %= list.length(); //z 다음에 a가 되도록 하기 위해서! list size가 22이면 0번쨰~21번째이고, 22번째가 될 경우에는 22 % 22해서 다시 0 되도록
      answer[i] = list[pos];
   }
    
    return answer;
}
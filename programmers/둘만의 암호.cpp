#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
https://school.programmers.co.kr/learn/courses/30/lessons/155652?language=cpp

���ڿ� �ε��� ����!
�ݺ������� ���� ���ذ��� �ε����� �����ִ� ������� �����ߴµ� �ڲ� �ð��ʰ� ����.
skip �� ���ĺ� �����ϰ� list �����, find �Լ��� ��ġ ���ؼ� �ٷ� index ������� �ð��ʰ� ���� Ǯ�� ����
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
      pos %= list.length(); //z ������ a�� �ǵ��� �ϱ� ���ؼ�! list size�� 22�̸� 0����~21��°�̰�, 22��°�� �� ��쿡�� 22 % 22�ؼ� �ٽ� 0 �ǵ���
      answer[i] = list[pos];
   }
    
    return answer;
}
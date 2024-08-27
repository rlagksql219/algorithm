#include <iostream>
using namespace std;

int main() {
  string str;
  char arr[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
  int cnt;
  while (getline(cin, str)) {
    if (str == "#")
      break;
    cnt = 0;
    for (int i = 0; i < str.length(); i++) {
      for (char ch : arr) {
        if (str[i] == ch)
          cnt++;
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}
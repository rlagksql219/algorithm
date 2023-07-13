/*#include <string>
#include <iostream>

using namespace std;

int main() {
	string str;
	int n;

	cin >> str >> n;
	int cursor = str.size();
	for (int i = 0; i < n; i++) {
		char tmp;
		cin >> tmp;

		if (tmp == 'L') {
			if (cursor != 0)
				cursor--;
		}
		else if (tmp == 'D') {
			if (cursor != str.size())
				cursor++;
		}
		else if (tmp == 'B') {
			if (cursor != 0) {
				str.erase(cursor - 1);
				//str = str.substr(0, str.size() - 1);
				cursor--;
			}
		}
		else {
			string insert_tmp;
			cin >> insert_tmp;
			str.insert(cursor, insert_tmp);
			cursor++;
		}
	}

	cout << str;

	return 0;
}*/


#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    int M;
    string s = "";
    stack<char> left;
    stack<char> right;

    cin >> s;

    for (int i = 0; i < (int)s.size(); i++)
    {
        left.push(s[i]);
    }

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        char cmd, c;
        cin >> cmd;

        if (cmd == 'L')
        {
            if (!left.empty())
            {
                right.push(left.top());
                left.pop();
            }
        }
        else if (cmd == 'D')
        {
            if (!right.empty())
            {
                left.push(right.top());
                right.pop();
            }
        }
        else if (cmd == 'B')
        {
            if (!left.empty())
            {
                left.pop();
            }
        }
        else if (cmd == 'P')
        {
            cin >> c;
            left.push(c);
        }
    }

    // left에 있는 원소들 모두 right로 이동!
    while (!left.empty())
    {
        right.push(left.top());
        left.pop();
    }

    // right에 있는 원소 출력
    while (!right.empty())
    {
        cout << right.top();
        right.pop();
    }
}
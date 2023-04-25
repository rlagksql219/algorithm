#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
int roma[129]; //아스키코드 범위
string roma2[1001]; // 문제 범위

int romtonum(string tmp) {
	int value = roma[tmp[0]];

	for (int i = 1; i < tmp.size(); i++) {
		if (roma[tmp[i - 1]] < roma[tmp[i]]) // IV, IX, XL, XC, CD, CM
			// *2 해주는 이유 : XL이면 40 더해야 하는데 이미 반복문에서 X에 해당하는 10을 더했으므로 한번 더 빼줘야 함
			value += roma[tmp[i]] - (roma[tmp[i - 1]] * 2);
		else
			value += roma[tmp[i]];
	}

	return value;
}


string numtorom(int num) {
	string tmp;

	switch (num) {
	case 0:		return "";
	case 1:		return "I";
	case 5:		return "V";
	case 10:	return "X";
	case 50:	return "L";
	case 100:	return "C";
	case 500:	return "D";
	case 1000:	return "M";
	case 4:		return "IV";
	case 9:		return "IX";
	case 40:	return "XL";
	case 90:	return "XC";
	case 400:	return "CD";
	case 900:	return "CM";
	
	default:
		if (num/10 == 0) { // num이 한 자리 수일 경우
			if (num > 5) {
				num -= 5;
				tmp += numtorom(5);
			}
			if (num % 3 == 1)	tmp += "I";
			if (num % 3 == 2)	tmp += "II";
			if (num % 3 == 0)	tmp += "III";
		}
		else if (num / 100 == 0) { // 두 자리 수
			if (num > 50) {
				num -= 50;
				tmp += numtorom(50);
			}
			if ((num/10) % 3 == 1)	tmp += "X";
			if ((num/10) % 3 == 2)	tmp += "XX";
			if ((num/10) % 3 == 0)	tmp += "XXX";
		}
		else if (num / 1000 == 0) { // 세 자리 수
			if (num > 500) {
				num -= 500;
				tmp += numtorom(500);
			}
			if ((num / 100) % 3 == 1)	tmp += "C";
			if ((num / 100) % 3 == 2)	tmp += "CC";
			if ((num / 100) % 3 == 0)	tmp += "CCC";
		}
		else if (num / 10000 == 0) { // 네 자리 수
			for (int i = 1; i <= (num / 1000); i++)
				tmp += "M";
		}

	}

	return tmp;
}


int main() {
	string str1, str2;
	string result;

	roma['I'] = 1;
	roma['V'] = 5;
	roma['X'] = 10;
	roma['L'] = 50;
	roma['C'] = 100;
	roma['D'] = 500;
	roma['M'] = 1000;

	cin >> str1 >> str2;
	int num = romtonum(str1) + romtonum(str2);
	cout << num << '\n';

	int ten = 10;
	while (num != 0) {
		result.insert(0, numtorom(num % ten));
		num -= num % ten;
		ten *= 10;

		/*
		numtorom = 3 -> 90 -> 400 -> 2000
		result = III -> XC III -> CD XCIII -> MM CDXCIII
		num = (2493) -> 2490 -> 2400 -> 400 -> 2000
		tem = 100 -> 1000 -> 10000 -> 100000
		*/
	}

	cout << result << '\n';

	return 0;
}
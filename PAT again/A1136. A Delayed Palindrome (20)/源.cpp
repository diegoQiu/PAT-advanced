#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string add(string a) {
	string b = a, ans;
	int len = a.length();
	reverse(b.begin(),b.end());
	int carry = 0;
	for (int i = 0; i < len; i++) {
		int num = (a[i] - '0' + b[i] - '0') + carry;
		carry = 0;
		if (num >= 10) {
			carry = 1;
			num -= 10;
		}
		ans += char(num +'0');
	}
	if (carry == 1)
		ans += '1';
	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {
	string str;
	cin >> str;
	int num = 0;
	while (num < 10) {
		string t = str;
		reverse(t.begin(), t.end());
		if (str == t) {
			cout << str << " is a palindromic number.";
			break;
		}
		else {
			cout << str << " + " << t << " = " << add(str) << endl;
			num++;
			str = add(str);
		}
	}
	if (num == 10)
		cout << "Not found in 10 iterations.";
	return 0;
}
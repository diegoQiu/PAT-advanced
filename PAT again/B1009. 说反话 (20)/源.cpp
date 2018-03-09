#include<iostream>
#include<string>
using namespace std;
int main() {
	string str;
	string ans[90];
	getline(cin, str);
	int r = 0;
	int h = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != ' ') {
			ans[r] += str[i];
		} else {
			r++;
		}
	}
	for (int i = r; i >= 0; i--) {
		cout << ans[i];
		if (i > 0)
			printf(" ");
	}
	return 0;
}
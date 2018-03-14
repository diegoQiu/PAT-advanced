#include<iostream>
#include<string>
using namespace std;

char a[11][6] = { "zero","one","two","three","four","five",
"six","seven","eight","nine" };

int main() {
	string str;
	cin >> str;
	int num = 0;
	for (int i = 0; i < str.length(); i++) {
		num += str[i] - '0';
	}
	string ans = to_string(num);
	for (int i = 0; i < ans.length(); i++) {
		printf("%s", a[ans[i] - '0']);
		if (i < ans.length() - 1)
			printf(" ");
	}
	return 0;
}
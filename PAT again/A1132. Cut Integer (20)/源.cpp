#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int N;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str, str1, str2;
		cin >> str;
		int j;
		for (j = 0; j < str.length() / 2; j++) {
			str1 += str[j];
		}
		for (; j < str.length(); j++) {
			str2 += str[j];
		}
		int a = stoi(str1);
		int b = stoi(str2);
		int c = stoi(str);
		if (a*b != 0 && c % (a*b) == 0)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
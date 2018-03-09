#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	char ans[40][40];
	int n, n1, n2, n3;
	cin >> s;
	 n = s.length();
	 n1 = n3 = (n + 2) / 3;
	 n2 = n - n1 - n1 + 2;
	 for (int i = 1; i <= n1; i++) {
		 for (int j = 1; j <= n2; j++) {
			 ans[i][j] = ' ';
		 }
	 }
	 int cnt = 0;
	 for (int i = 1; i <= n1; i++) {
		 ans[i][1] = s[cnt++];
	 }
	 for (int j = 2; j <= n2; j++) {
		 ans[n1][j] = s[cnt++];
	 }
	 for (int i = n1 - 1; i >= 1; i--) {
		 ans[i][n2] = s[cnt++];
	 }
	 for (int i = 1; i <= n1; i++) {
		 for (int j = 1; j <= n2; j++) {
			 printf("%c", ans[i][j]);
		 }
		 printf("\n");
	 }
	return 0;
}
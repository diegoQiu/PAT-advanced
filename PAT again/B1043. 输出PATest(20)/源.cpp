#include<iostream>
#include<string>
using namespace std;
const int maxn = 10005;
int P, A, T, e, s, t;
int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'P')
			P++;
		else if (str[i] == 'A')
			A++;
		else if (str[i] == 'T')
			T++;
		else if (str[i] == 'e')
			e++;
		else if (str[i] == 's')
			s++;
		else if (str[i] == 't')
			t++;
	}
	while (1) {
		if (P > 0) {
			P--;
			printf("P");
		}
		if (A > 0) {
			printf("A");
			A--;
		}
		if (T > 0) {
			printf("T");
			T--;
		}
		if (e > 0) {
			printf("e");
			e--;
		}
		if (s > 0) {
			printf("s");
			s--;
		}
		if (t > 0) {
			printf("t");
			t--;
		}
		if ((!P) && (!A) && (!T) && (!e) && (!s) && (!t))
			break;
	}
}
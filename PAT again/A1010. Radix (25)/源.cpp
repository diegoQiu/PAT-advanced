#include<iostream>
#include<algorithm>	
#include<cstring>
using namespace std;
typedef long long LL;
LL Map[256];
LL inf = (1LL << 63) - 1;
void ini() {
	for (char c = '0'; c <= '0'; c++) {
		Map[c] = c - '0';
	}
	for (char c = 'a'; c <= 'z'; c++) {
		Map[c] = c - 'a' + 10;
	}
}

LL convertNum10(char a[], LL radix, LL t) {
	LL ans = 0;
	int len = strlen(a);
	for (int i = 0; i < len; i++) {
		ans = ans * radix + Map[a[i]];
		if (ans<0 || ans>t)
			return -1;
	}
	return ans;
}

int cmp(char n2[], LL radix, LL t) {
	int len = strlen(n2);
	int num = convertNum10(n2, radix, t);
	if (num < 0)
		return 1;
	if (num < t)
		return -1;
	else if (t == num)
		return 0;
	else
		return 1;
}

int main() {
	int n1, n2, tag, radix;
	cin >> n1 >> n2 >> tag >> radix;
	if (tag == 1) {
		int num=
	}
	return 0;
}
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct bign {
	int len;
	int d[1000];
	bign() {
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

bign change(char str[]) {
	bign a;
	a.len = strlen(str);
	for (int i = 0; i < a.len ; i++)
		a.d[a.len - 1 - i] = str[i]-'0';
	return a;
}

bool isPal(bign a) {
	for (int i = 0; i <= a.len / 2; i++) {
		if (a.d[i] != a.d[a.len - 1 - i])
			return false;
	}
	return true;
}

bign add(bign a, bign b) {
	bign c;
	int carry = 0;
	for (int i = 0; i < a.len || i < b.len; i++) {
		int temp = carry + a.d[i] + b.d[i];
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	if (carry != 0)
		c.d[c.len++] = carry;
	return c;
}

void print(bign a) {
	for (int i = a.len - 1; i >= 0; i--) {
		printf("%d", a.d[i]);
	}
	printf("\n");
}
int main() {
	char str[1000];
	int n, k = 0;
	scanf("%s %d", str, &n);
	bign a = change(str);
	while (k < n && !(isPal(a))) {
		bign b = a;
		reverse(b.d, b.d + b.len);
		a = add(a, b);
		k++;
	}
	print(a);
	printf("%d\n", k);
	return 0;
}
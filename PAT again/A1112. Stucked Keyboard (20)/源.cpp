#include<iostream>
#include<cstring>
const int maxn = 1010;
const int maxm = 128;
char str[maxn];
int k, len, isStuck[maxm] = { 0 };
void judgeStuck() {
	int i = 0, j = 0;
	while (i < len) {
		while (j < len&&str[i] == str[j]) {
			j++;
		}
		if ((j - i)% k != 0) {
			isStuck[str[i]] = 1;
		}
		i = j;
	}
}

int main() {
	scanf("%d %s", &k, str);
	len = strlen(str);
	judgeStuck();
	for (int i = 0; i < len; i++) {
		if (isStuck[str[i]] == 0) {
			printf("%c", str[i]);
			isStuck[str[i]] = -1;
		}
	}
	printf("\n");
	for (int i = 0; i < len;) {
		printf("%c", str[i]);
		if (isStuck[str[i]] == -1) {
			i += k;
		}
		else {
			i++;
		}
	}
	return 0;
}
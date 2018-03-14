#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;


int used[10];
int main() {
	char num[22];
	scanf("%s", num);
	int len = strlen(num);
	int carry = 0;
	for (int i = len - 1; i >= 0; i--) {
		int temp = num[i] - '0';
		used[temp]++;
		temp = temp * 2 + carry;
		if (temp >= 10)
			carry = 1;
		else
			carry = 0;
		temp %= 10;
		num[i] = (temp + '0');
		used[temp]--;
	}
	bool flag =false;
	for (int i = 0; i < 10; i++) {
		if (used[i] != 0) {
			flag = true;
			break;
		}
	}
	if (flag)
		printf("No\n");
	else
		printf("Yes\n");
	if (carry == 1)
		printf("1");
	printf("%s", num);
	return 0;
}
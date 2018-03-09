#include<iostream>
#include<algorithm>
using namespace std;
int a[5], b[5];
int n;
void numToArray(int x, int array[]) {
	int cnt = 0;
	while (1) {
		array[cnt++] = x % 10;
		x /= 10;
		if (cnt == 4)
			break;
	}
}

int arrayToNum(int array[]) {
	int ans = 0;
	for (int i = 3; i >= 0; i--) {
		ans = ans * 10 + array[i];
	}
	return ans;
}

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	cin >> n;
	if (n == 6174) {
		printf("7641 - 1467 = 6174\n");
		return 0;
	}
	while (n != 0 && n != 6174) {
		numToArray(n, a);
		numToArray(n, b);
		sort(a, a + 4, cmp);
		sort(b, b + 4);
		int y = arrayToNum(a);
		int x = arrayToNum(b);
		printf("%04d - %04d = %04d\n", x, y, x - y);
		n = x - y;
	}
	
	return 0;
}
#include<iostream>
#include<string>
using namespace std;
int a, b;
bool isPal(int n) {
	string a = to_string(n);
	for (int i = 0; i <= a.length() / 2; i++) {
		if (a[i] != a[a.length() - 1 - i])
			return false;
	}
	return true;
}


int main() {
	int a, b;
	cin >> a >> b;
	int arry[40], index = 0;
	while (a != 0) {//这里使用while的风险在有可能a本身为0，一次都不执行
		//所以最后要特判一下
		arry[index++] = a % b;
		a /= b;
	}
	bool flag = false;
	for (int i = 0; i < index / 2; i++) {
		if (arry[i] != arry[index - 1 - i]) {
			printf("No\n");
			flag = true;
			break;
		}
	}
	if (!flag)
		printf("Yes\n");
	for (int i = index - 1; i >= 0; i--) {
		printf("%d", arry[i]);
		if (i > 0)
			printf(" ");
	}
	if (index == 0)
		printf("0");
	return 0;
}
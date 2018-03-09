#include<iostream>
#include<string>
#include<cstring>
using namespace std;

char week[8][5] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
int main() {
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	int i;
	int num;
	for (i = 0; i < a.length() && i < b.length(); i++) {
		if (a[i] >= 'A'&&a[i] <= 'G'&&a[i] == b[i]) {
			num = a[i] - 'A';
			cout << week[num] << " ";
			break;
		}
	}
	for (i++; i < a.length() && i < b.length(); i++) {
		if (a[i] >= '0'&&a[i] <= '9'&&a[i] == b[i]) {
			printf("%02d", a[i] - '0');
			break;
		} else if (a[i] >= 'A'&&a[i] <= 'N'&&a[i] == b[i]) {
			printf("%02d", a[i] - 'A' + 10);
			break;
		}
	}
	for (int i = 0; i < c.length() && i < d.length(); i++) {
		if (((c[i] >= 'a'&&c[i] <= 'z') || (c[i] >= 'A'&&c[i] <= 'Z')) && c[i] == d[i]) {
			printf(":%02d", i);
			break;
		}
	}
	return 0;
}
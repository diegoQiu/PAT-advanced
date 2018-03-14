#include<iostream>
#include<string>
using namespace std;
int main() {
	string str;
	cin >> str;
	int left = 0, right = 0;
	char c = str[0];
	if (c == '-')
		printf("%c", c);
	int pos = 0;
	while (str[pos] != 'E')pos++;
	int exp = 0;
	for (int i = pos + 2; i < str.length(); i++) {
		exp = exp * 10 + (str[i] - '0');
	}
	if (exp == 0) {
		for (int i = 1; i < pos; i++) {
			printf("%c", str[i]);
		}
	}
	if (str[pos + 1] == '-') {
		printf("0.");
		for (int i = 0; i < exp - 1; i++) {
			printf("0");
		}
		printf("%c", str[1]);
		for (int i = 3; i< pos; i++) {
			printf("%c", str[i]);
		}
	}
	else {
		for (int i = 1; i < pos; i++) {
			if (str[i] == '.')
				continue;
			printf("%c", str[i]);
			if (i == exp + 2 && pos - 3 != exp) {
				printf(".");
			}
		}
		for (int i = 0; i < exp - (pos - 3); i++) {
			printf("0");
		}
	}
	return 0;
}
#include<iostream>
#include<string>
using namespace std;
int main() {
	int N;
	cin >> N;
	string str[101];
	int minLen = 290;
	getchar();//接收N后面的换行符
	for (int i = 0; i < N; i++) {
		//cin >> str[i];因为样列中有空格，所以这样并不能输入整行
		getline(cin, str[i]);
		if (str[i].length() < minLen) {
			minLen = str[i].length();
		}
		for (int j = 0; j <str[i].length() / 2; j++) {
			char c = str[i][j];
			str[i][j] = str[i][str[i].length() - 1 - j];
			str[i][str[i].length() - 1 - j] = c;
		}
	}
	int cnt = 0;
	for (int i = 0; i < minLen; i++) {
		char a = str[0][i];
		bool flag = true;
		for (int j = 1; j < N; j++) {
			if (str[j][i] != a) {
				flag = false;
				break;
			}
		}
		if (flag)
			cnt++;
		else
			break;
	}
	if (cnt == 0) {
		cout << "nai" << endl;
	}
	else {
		for (int i= cnt-1; i >=0; i--) {
			printf("%c", str[0][i]);
		}
	}
	return 0;
}
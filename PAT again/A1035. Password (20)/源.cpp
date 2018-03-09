#include<iostream>
#include<string>	
using namespace std;
int main() {
	int N, cnt = 0;
	cin >> N;
	string ans[1001];
	for (int i = 0; i < N; i++) {
		string name, password;
		cin >> name >> password;
		bool flag = false;
		for (int j = 0; j < password.length(); j++) {
			if (password[j] == '1') {
				password[j] = '@';
				flag = true;
			}
			else if (password[j] == '0') {
				password[j] = '%';
				flag = true;
			} else if (password[j] == 'l') {
				password[j] = 'L';
				flag = true;
			} else if (password[j] == 'O') {
				password[j] = 'o';
				flag = true;
			}
		}
		if (flag) {
			ans[cnt] += name;
			ans[cnt] += ' ';
			ans[cnt] += password;
			cnt++;
		}
	}
	if (cnt == 0 && N == 1) {
		cout << "There is 1 account and no account is modified" << endl;
	} else if (cnt == 0 && N > 1) {
		cout << "There are " << N << " accounts and no account is modified" << endl;
	}
	else {
		cout << cnt << endl;
		for (int i = 0; i < cnt; i++) {
			cout << ans[i] << endl;
		}
	}
	return 0;
}
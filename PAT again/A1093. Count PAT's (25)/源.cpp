#include<iostream>
#include<string>
using namespace std;
int leftP[100005];
const int MOD = 1000000007;
int main() {
	string str;
	cin >> str;
	int len = str.length();
	int rightT=0;
	int ans = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == 'P') {
			leftP[i] = leftP[i - 1] + 1;
		} else
			leftP[i] = leftP[i - 1];
	}
	for (int i = len - 1; i >= 0; i--) {
		if (str[i] == 'T') {
			rightT++;
		}
		else if (str[i] == 'A') {
			ans = (ans + leftP[i] * rightT) % MOD;
		}
	}
	cout << ans;
	return 0;
}
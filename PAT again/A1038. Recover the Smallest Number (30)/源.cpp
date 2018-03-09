#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(string a, string b) {
	return a+b < b+a;
}
int main() {
	int N;
	cin >> N;
	string str[10001];
	string ans;
	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}
	sort(str, str + N, cmp);
	for (int i = 0; i < N; i++) {
		ans += str[i];
	}
	while (ans.size()!=0&&ans[0]=='0') {
		ans.erase(ans.begin());
	}
	if (ans.size() == 0)
		cout << "0" << endl;
	else
		cout << ans << endl;
	return 0;
}
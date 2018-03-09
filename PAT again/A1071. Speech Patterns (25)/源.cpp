#include<iostream>
#include<map>	
#include<string>
using namespace std;
map<string, int> cnt;
bool isLegal(char c) {
	if (c >= '0'&&c <= '9')
		return true;
	else if (c >= 'a'&&c <= 'z')
		return true;
	else if (c >= 'A'&&c <= 'Z')
		return true;
	return false;
}
int main() {
	string str;
	getline(cin, str);
	int i = 0;
	while (i < str.length()) {
		string s;
		while (i < str.length() && isLegal(str[i])) {

			if (str[i] >= 'A'&&str[i] <= 'Z')
				str[i] += 32;
			s += str[i];

			i++;
		}
		if (s != "") {
			if (cnt.find(s) != cnt.end()) {
				cnt[s]++;
			} else {
				cnt[s] = 1;
			}
		}
		while (i < str.length() && isLegal(str[i]) == false) {
			i++;
		}
	}
	int maxn = 0;
	string ans;
	for (auto it = cnt.begin(); it != cnt.end(); it++) {
		if (it->second > maxn) {
			maxn = it->second;
			ans = it->first;
		}
	}
	cout << ans << " " << maxn << endl;
	return 0;
}
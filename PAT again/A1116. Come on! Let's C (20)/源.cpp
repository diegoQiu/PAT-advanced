#include<iostream>
#include<string>
#include<cmath>
#include<map>
using namespace std;
const int maxn = 10001;

map<string, int> mp;
map<int, string> intToStr;
bool vis[maxn];

bool isPrime(int n) {
	int sqr = (int)sqrt(1.0*n);
	for (int i = 2; i <= sqr; i++) {
		if (n%i == 0)
			return false;
	}
	return true;
}
int main() {
	int n, k;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		mp[str] = i;
		intToStr[i] = str;
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		string str;
		cin >> str;
		if (mp.find(str) == mp.end()) {
			cout << str << ": Are you kidding?" << endl;
		}
		else {
			int x = mp[str];
			if (vis[x] == false) {
				vis[x] = true;
				if (x == 1) {
					cout << str << ": Mystery Award"<<endl;
				}
				else if (isPrime(x)) {
					cout << str << ": Minion" << endl;
				}
				else {
					cout << str << ": Chocolate" << endl;
				}
			}
			else {
				cout << str << ": Checked" << endl;
			}
		}
	}
	return 0;
}
#include<iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		long long ans = a + b;
		bool flag;
		if (a > 0 && b > 0 && ans < 0)
			flag = true;
		else if (a < 0 && b < 0 && ans >= 0)
			flag = false;
		else if (ans > c)
			flag = true;
		else
			flag = false;
		if(flag)
			cout << "Case #" << i << ": true" << endl;
		else 
			cout << "Case #" << i << ": false" << endl;
	}
	return 0;
}
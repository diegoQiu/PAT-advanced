#include<iostream>
using namespace std;
typedef long long LL;

struct Fraction {
	LL up, down;
}fra[101];

int gcd(LL a,LL b) {
	return !b ? a : gcd(b, a%b);
}

void showFraction(Fraction a) {
	if (a.down==1) {
		printf("%lld", a.up);
		return;
	}
	else if (abs(a.up) > a.down) {
		LL temp = a.up / a.down;
		a.up = abs(a.up)%a.down;
		printf("%lld %lld/%lld", temp, a.up, a.down);
	}
	else {
		printf("%lld/%lld", a.up, a.down);
	}
	return;
}

Fraction reduction(Fraction a) {
	if (a.down < 0) {
		a.down = (-a.down);
		a.up = -a.up;
	}
	if (a.up == 0) {
		a.down = 1;
	}
	else {
		LL d = gcd(a.up, a.down);
		a.up /= d;
		a.down /= d;
	}
	return a;
}

Fraction add(Fraction a, Fraction b) {
	Fraction c;
	c.down = a.down*b.down;
	c.up = a.up*b.down + a.down*b.up;
	return reduction(c);
}
int main() {
	int n;
	cin >> n;
	Fraction sum, temp;
	sum.up = 0;
	sum.down = 1;
	for (int i = 0; i < n; i++) {
		scanf("%lld/%lld", &temp.up, &temp.down);
		sum = add(sum, temp);
	}
	showFraction(sum);
	return 0;
}
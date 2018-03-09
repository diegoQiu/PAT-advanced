#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;

LL gcd(LL a, LL b) {
	return !b ? a : gcd(b, a%b);
}

struct Fraction {
	LL up, down;
};

Fraction reduction(Fraction a) {
	if (a.down < 0) {
		a.down = -a.down;
		a.up = -a.up;
	}
	if (a.up == 0) {
		a.down = 1;
	}
	else {
		int d = gcd(abs(a.up), (a.down));
		a.up /= d;
		a.down /= d;
	}
	return a;
}

Fraction add(Fraction a, Fraction b) {
	Fraction c;
	c.down = a.down*b.down;
	c.up = a.up*b.down + b.up*a.down;
	return reduction(c);
}

Fraction sub(Fraction a, Fraction b) {
	Fraction c;
	c.down = a.down*b.down;
	c.up = a.up*b.down - a.down*b.up;
	return reduction(c);
}

Fraction time(Fraction a, Fraction b) {
	Fraction c;
	c.down = a.down*b.down;
	c.up = a.up*b.up;
	return reduction(c);
}

Fraction div(Fraction a, Fraction b) {
	Fraction c;
	c.down = a.down*b.up;
	c.up = a.up*b.down;
	return reduction(c);
}

void print(Fraction a) {
	reduction(a);
	if (a.up < 0)
		printf("(");
	if (a.down == 1) {
		printf("%lld", a.up);
	}
	else if (abs(a.up) > a.down) {
		int temp = a.up / a.down;
		printf("%d %lld/%lld", temp, abs(a.up)%a.down, a.down);
	}
	else {
		printf("%lld/%lld", a.up, a.down);
	}
	if (a.up < 0)
		printf(")");
}

int main() {
	Fraction a, b;
	scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
	a = reduction(a);
	b = reduction(b);
	print(a);
	printf(" + ");
	print(b);
	printf(" = ");
	print(add(a, b));
	printf("\n");
	print(a);
	printf(" - ");
	print(b);
	printf(" = ");
	print(sub(a, b));
	printf("\n");
	print(a);
	printf(" * ");
	print(b);
	printf(" = ");
	print(time(a, b));
	printf("\n");
	print(a);
	printf(" / ");
	print(b);
	printf(" = ");
	if (b.up == 0) {
		printf("Inf");
	}
	else {
		print(div(a, b));
	}
	printf("\n");
}
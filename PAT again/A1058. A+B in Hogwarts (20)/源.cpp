#include<iostream>
using namespace std;
struct coin {
	int g;
	int s;
	int k;
};
coin add(coin x, coin y) {
	coin z;
	z.k = (x.k + y.k) % 29;
	int carry = (x.k + y.k) / 29;
	z.s = (carry + x.s + y.s) % 17;
	carry= (carry + x.s + y.s) / 17;
	z.g = carry + x.g + y.g;
	return z;
}
int main() {
	coin a, b, c;
	scanf("%d.%d.%d %d.%d.%d", &a.g, &a.s, &a.k, &b.g, &b.s, &b.k);
	c = add(a, b);
	printf("%d.%d.%d", c.g, c.s, c.k);
	return 0;
}
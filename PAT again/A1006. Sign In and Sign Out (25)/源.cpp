#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

struct Node {
	char id[20];
	int hh, mm, ss;
}temp,f,l;

void init() {
	f.hh = 23;
	f.mm = 59;
	f.ss = 59;
	l.hh = 0;
	l.mm = 0;
	l.ss = 0;
	return;
}

bool islate(Node a, Node b) {
	if (a.hh != b.hh)
		return a.hh > b.hh;
	if (a.mm != b.mm)
		return a.mm > b.mm;
	else
		return a.ss > b.ss;
}
int main() {
	int n;
	cin >> n;
	init();
	for (int i = 0; i < n; i++) {
		scanf("%s %d:%d:%d", temp.id, &temp.hh, &temp.mm, &temp.ss);
		if (islate(f, temp))
			f = temp;
		scanf("%d:%d:%d", &temp.hh, &temp.mm, &temp.ss);
		if (islate(temp, l))
			l = temp;
	}
	cout << f.id << " " << l.id << endl;
	return 0;
}
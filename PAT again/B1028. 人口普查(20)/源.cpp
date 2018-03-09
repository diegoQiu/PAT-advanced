#include<iostream>
using namespace std;

const int maxn = 100005;
struct birthday {
	int year;
	int month;
	int day;
	char id[6];
}bir[maxn];
birthday old, young,leftone,rightone;

void init() {
	young.year = leftone.year = 1814;
	old.year = rightone.year = 2014;
	young.month = old.month = leftone.month = rightone.month = 9;
	young.day = old.day = leftone.day = rightone.day = 6;

}

bool isLess(birthday a,birthday b) {//a年纪比b小，返回true
	if (a.year > b.year)
		return true;
	if (a.year == b.year&&a.month > b.month)
		return true;
	if (a.year == b.year&&a.month == b.month&&a.day >= b.day)
		return true;
	else 
		return false;
}


int main() {
	int n;
	int cnt = 0;
	cin >> n;
	init();
	for (int i = 0; i < n; i++) {
		bool f1, f2;
		scanf("%s %d/%d/%d", bir[i].id, &bir[i].year, &bir[i].month, &bir[i].day);
		if (isLess(bir[i],leftone)&&isLess(rightone,bir[i])) {
			cnt++;
			if (isLess(bir[i], young))
				young = bir[i];
			if (isLess(old, bir[i]))
				old = bir[i];
		}
	}
	if (cnt == 0)
		cout << "0";
	
	else printf("%d %s %s\n", cnt, old.id, young.id);
	return 0;
}
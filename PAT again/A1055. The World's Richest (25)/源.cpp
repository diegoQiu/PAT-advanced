#include<iostream>
#include<algorithm>	
#include<cstring>
#include<string>
using namespace std;
struct Rich {
	char name[10];
	int age;
	int money;
}rich[100005];
bool cmp(Rich a,Rich b){
	if (a.money != b.money)
		return a.money > b.money;
	else if (a.age != b.age)
		return a.age < b.age;
	else
		return strcmp(a.name,b.name)<0;
}
int main() {
	int n, m,k, amin, amax;
	scanf("%d %d", &n, &k);
	getchar();
	for (int i = 0; i < n; i++) {
		scanf("%s", rich[i].name);
		scanf("%d %d",  &rich[i].age, &rich[i].money);
	}
	sort(rich, rich + n, cmp);
	for (int i = 0; i < k; i++) {
		int cnt = 0;
		scanf("%d %d %d", &m, &amin, &amax);
		printf("Case #%d:\n", i + 1);
		for (int j = 0; j < n; j++) {
			if (rich[j].age >= amin && rich[j].age <= amax) {
				cnt++;
				if (cnt <= m) {
					printf("%s ", rich[j].name);
					printf("%d %d\n", rich[j].age, rich[j].money);
				}
				else
					break;
			}
		}
		if (cnt == 0)
			printf("None\n");
	}
	return 0;
}
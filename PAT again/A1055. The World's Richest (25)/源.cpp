#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int N, K, M, Amin, Amax;
int Age[maxn];

struct Rich {
	char name[10];
	int age, worth;
}rich[maxn],valid[maxn];

bool cmp(Rich a, Rich b) {
	if (a.worth != b.worth)
		return a.worth > b.worth;
	else if (a.age != b.age)
		return a.age < b.age;
	else
		return strcmp(a.name,b.name)<0;
}


int main() {
	cin >> N >> K;
	getchar();
	for (int i = 0; i < N; i++) {
		scanf("%s %d %d", rich[i].name, &rich[i].age,& rich[i].worth);
	}
	sort(rich, rich + N, cmp);
	int num = 0;
	for (int i = 0; i < maxn; i++) {
		int age = rich[i].age;
		if (Age[age] < 100) {
			Age[age]++;
			valid[num++] = rich[i];
		}
	}
	for (int i = 1; i <= K; i++) {
		printf("Case #%d:\n", i);
		scanf("%d %d %d", &M, &Amin, &Amax);
		int num = 0;
		for (int i = 0; i < N; i++) {
			if (valid[i].age >= Amin && valid[i].age <= Amax) {
				num++;
				printf("%s %d %d\n",valid[i].name,valid[i].age, valid[i].worth);
				if (num == M)
					break;
			}
		}
		if (num == 0)
			printf("None\n");
	}
	return 0;
}
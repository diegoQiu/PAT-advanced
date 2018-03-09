#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

struct student {
	char id[7];
	char name[9];
	int grade;
}stu[100005];
int C;
bool cmp(student a, student b) {
	if (C == 1) {
		return strcmp(a.id, b.id) < 0;
	} else if (C == 2) {
		if (strcmp(a.name, b.name) != 0) {
			return strcmp(a.name, b.name) < 0;
		}
		else {
			return strcmp(a.id, b.id) < 0;
		}
	}
	else {
		if (a.grade != b.grade)
			return a.grade < b.grade;
		else
			return strcmp(a.id, b.id) < 0;
	}
}
int main() {
	int N;
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		scanf("%s %s %d", stu[i].id, stu[i].name, &stu[i].grade);
	}
	sort(stu, stu + N, cmp);
	for (int i = 0; i < N; i++) {
		printf("%s %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
	}
	return 0;
}
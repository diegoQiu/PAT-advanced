#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct student {
	int uid, pid;
	int score[5];
	bool flag[5];
	int solve;
	bool right;
}stu[100010];

int p[6];
bool cmp(student a, student b) {
	if (a.score[0] != b.score[0])
		return a.score[0] > b.score[0];
	else if (a.solve != b.solve)
		return a.solve > b.solve;
	else
		return a.pid < b.pid;
}
bool show[100010] = { false };

int main() {
	int n, k, m;
	int cnt = 0;
	cin >> n >> k >> m;
	for (int i = 1; i <= k; i++)
		cin >> p[i];
	student temp;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &temp.uid, &temp.pid, &temp.score[0]);
		stu[temp.uid].uid = temp.uid;
		if (temp.score[0] != -1) {
			stu[i].right = true;
		}
		stu[temp.uid].flag[temp.pid] = true;
		if (show[temp.uid] == false) {
			show[temp.uid] == true;
			cnt++;
		}
		if (temp.score[0] == p[temp.pid]&&)
			stu[temp.uid].solve++;
		if (temp.score[0] > stu[temp.uid].score[temp.pid])
			stu[temp.uid].score[temp.pid] = temp.score[0];
	}
	for (int i = 0; i < 100010; i++) {
		for (int j = 1; j <= k; j++) {
			stu[i].score[0] += stu[i].score[j];
		}
	}
	sort(stu, stu + 100010, cmp);
	int r = 1;
	for (int i = 0; i < cnt; i++) {
		if (i > 0 && stu[i].score[0] == stu[i - 1].score[0]) {
			printf("%d", r);
		}
		else {
			printf("%d", i + 1);
			r = i + 1;
		}
		printf(" %05d %d", stu[i].uid, stu[i].score[0]);
		for (int j = 1; j <= k; j++) {
			if (stu[i].flag[j] == false)
				printf(" -");
			else
				printf(" %d", stu[i].score[j]);
		}
		printf("\n");
	}
	return 0;
}
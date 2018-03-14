#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 10010;
int n, k, m;

struct student {
	int id;
	int score[6];
	bool flag;
	int score_all;
	student() {
		for (int i = 1; i <= 6; i++) {
			score[i] = -1;
		}
		flag = false;
		solve = 0;
	}
	
	int solve;
}stu[10010];

int p[6];
bool cmp(student a, student b) {
	if (a.score_all != b.score_all)
		return a.score_all > b.score_all;
	else if (a.solve != b.solve)
		return a.solve > b.solve;
	else
		return a.id < b.id;
}

int main() {

	cin >> n >> k >> m;
	for (int i = 1; i <= k; i++)
		cin >> p[i];
	for (int i = 1; i <= n; i++) {
		stu[i].id = i;
	}
	student temp;
	for (int i = 0; i < m; i++) {
		int uid, pid, partial_score;
		scanf("%d %d %d", &uid, &pid, &partial_score);
		if (stu[uid].score[pid] == -1 && partial_score == -1)
			stu[uid].score[pid] = 0;
		if (partial_score != -1)
			stu[uid].flag = true;
		if (partial_score == p[pid] && stu[uid].score[pid] < p[pid])
			stu[uid].solve++;
		if (partial_score > stu[uid].score[pid])
			stu[uid].score[pid] = partial_score;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (stu[i].score[j] >=0)
				stu[i].score_all += stu[i].score[j];
		}
	}
	sort(stu+1, stu + n+1, cmp);
	int r = 1;
	for (int i = 1; i <=n; i++) {
		if (stu[i].flag==false) {
			return 0;
		}
		if (i > 0 && stu[i].score_all == stu[i - 1].score_all) {
			printf("%d", r);
		} else {
			r = i;
			printf("%d", r );
			
		}
		printf(" %05d %d", stu[i].id, stu[i].score_all);
		for (int j = 1; j <= k; j++) {
			if (stu[i].score[j] == -1)
				printf(" -");
			else
				printf(" %d", stu[i].score[j]);
		}
		printf("\n");
	}
	return 0;
}
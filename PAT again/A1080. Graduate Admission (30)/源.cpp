#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct student {
	int ge, gi, gf;
	int r;
	int stuID;
	int choice[6];
}stu[40001];

struct school {
	int quota;
	int id[40001];
	int stuNum;
	int lastAdmit;
}sch[101];
bool cmp(student a, student b) {
	if (a.gf != b.gf) {
		return a.gf > b.gf;
	} else
		return a.ge > b.ge;
}
bool cmp2(int a, int b) {
	return stu[a].stuID < stu[b].stuID;
}
vector<int> adopt[101];
int main() {
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		scanf("%d", &sch[i].quota);
		sch[i].lastAdmit = -1;
	}
	for (int i = 0; i < N; i++) {
		stu[i].stuID = i;
		scanf("%d %d", &stu[i].ge, &stu[i].gi);
		stu[i].gf = stu[i].ge + stu[i].gi;
		for (int j = 0; j < K; j++) {
			scanf("%d", &stu[i].choice[j]);
		}
	}
	sort(stu, stu + N, cmp);
	for (int i = 0; i < N; i++) {
		if (i > 0 && stu[i].gf == stu[i - 1].gf&&stu[i].ge == stu[i - 1].ge) {
			stu[i].r = stu[i - 1].r;
		} else {
			stu[i].r = i + 1;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			int cho = stu[i].choice[j];
			int num = sch[cho].stuNum;
			int last = sch[cho].lastAdmit;
			if (num < sch[cho].quota||(last!=-1&&stu[i].r==stu[last].r)) {
				sch[cho].id[num] = i;
				sch[cho].lastAdmit = i;
				sch[cho].stuNum++;
				break;
			} 
		}
	}
	for (int i = 0; i < M; i++) {
		if (sch[i].stuNum > 0) {
			sort(sch[i].id, sch[i].id + sch[i].stuNum, cmp2);
			for (int j = 0; j < sch[i].stuNum; j++) {
				printf("%d", stu[sch[i].id[j]].stuID);
				if (j < sch[i].stuNum - 1)
					printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
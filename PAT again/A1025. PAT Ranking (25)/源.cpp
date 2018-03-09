#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct student {
	string ID;
	int score;
	int locate;
	int local_rank;
}stu[30005];

bool cmp(student a, student b) {
	if (a.score != b.score)
		return a.score > b.score;
	else
		return a.ID < b.ID;
}
int main() {
	int N, K;
	cin >> N;
	int num = 0;
	for (int i = 0; i < N; i++) {
		cin >> K;
		for (int j = 0; j < K; j++) {
			student temp;
			temp.locate = i + 1;
			cin >> temp.ID >> temp.score;
			stu[num] = temp;
			num++;
		}
		sort(stu + num - K, stu + num, cmp);
		stu[num - K].local_rank = 1;
		for (int j = num - K + 1; j < num; j++) {
			if (stu[j].score == stu[j - 1].score)
				stu[j].local_rank = stu[j - 1].local_rank;
			else
				stu[j].local_rank = j + 1 - (num - K);
		}
	}
	sort(stu, stu + num, cmp);
	int r = 1;
	cout << num << endl;
	for (int i = 0; i < num; i++) {
		if (i > 0 && stu[i].score != stu[i - 1].score) {
			r = i + 1;
		}
		cout << stu[i].ID << " " << r << " " << stu[i].locate << " " << stu[i].local_rank << endl;

	}
	return 0;
}
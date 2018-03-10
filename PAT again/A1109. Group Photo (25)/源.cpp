#include<iostream>	
#include<string>	
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 100001;
struct student {
	string name;
	int height;
}stu[maxn];

int n, k, row;
bool cmp(student a, student b) {
	if (a.height != b.height)
		return a.height > b.height;
	else
		return a.name < b.name;
}

int main() {
	cin >> n >> k;
	getchar();
	for (int i = 0; i < n; i++) {
		cin >> stu[i].name >> stu[i].height;
	}
	sort(stu, stu + n, cmp);
	int leftPos = 0;
	int num = n - (n / k) * (k - 1);
	bool flag = true;
	while (leftPos < n) {
		for (int i = (num % 2) ? num - 2 : num - 1; i >= 1; i -= 2) {
			cout << stu[leftPos+i].name<<" ";
		}
		for (int i = 0; i < num; i += 2) {
			cout << stu[leftPos + i].name;
			if (num - i > 2)
				printf(" ");
			else
				printf("\n");
		}
		leftPos += num;
		num = n / k;
	}
	return 0;
}
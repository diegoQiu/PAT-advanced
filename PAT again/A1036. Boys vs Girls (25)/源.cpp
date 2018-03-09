#include<cstdio>
#include<iostream>
using namespace std;
struct student {
	int g;
	char id[15], name[15];
	char gender;
}stu, fh, ml;

int main() {
	fh.g = -1;
	ml.g = 101;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> stu.name >> stu.gender >> stu.id >> stu.g;
		if (stu.gender == 'M') {
			if (stu.g < ml.g)
				ml = stu;
		} else {
			if (stu.g > fh.g)
				fh = stu;
		}
	}
	if (fh.g == -1)
		cout << "Absent" << endl;
	else
		cout << fh.name << " " << fh.id << endl;
	if (ml.g == 101)
		cout << "Absent" << endl;
	else
		cout << ml.name << " " << ml.id << endl;
	if (fh.g == -1 || ml.g == 101)
		cout << "NA" << endl;
	else
		cout << fh.g - ml.g << endl;
	return 0;
}
#include<iostream>
#include<cstring>	
using namespace std;


int main() {
	int n;
	cin >> n;
	double sum=0.0, temp;
	char str1[50], str2[50];
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%s", str1);
		sscanf(str1, "%lf", &temp);
		sprintf(str2, "%.2lf", temp);
		int flag = false;
		for (int j = 0; j < strlen(str1); j++) {
			if (str1[j] != str2[j]) {
				flag = true;
			}
		}
		if (flag||temp<-1000||temp>1000) {
			printf("ERROR: %s is not a legal number\n", str1);
		}
		else {
			sum += temp; cnt++;
		}
	}
	if (cnt == 1) {
		printf("The average of 1 number is %.2lf", sum);
	}
	else if (cnt == 0) {
		printf("The average of 0 numbers is Undefined");
	}
	else {
		printf("The average of %d numbers is %.2lf",cnt, sum / cnt);
	}
	return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 101;
int origin[maxn], temp[maxn], changed[maxn];
int n;

bool isSame(int a[], int b[]) {
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i])
			return false;
	}
	return true;
}

void showArray(int a[]) {
	for (int i = 0; i < n; i++) {
		printf("%d", a[i]);
		if (i < n - 1)
			printf(" ");
		else
			printf("\n");
	}
	return;
}
bool  insertion() {
	bool flag = false;
	for (int i = 1; i < n; i++) {
		if (i != 1 && isSame(temp, changed)) {
			flag = true;
		}
		int k = temp[i];
		int j = i;
		while (j > 0 && temp[j - 1] > k) {
			temp[j] = temp[j - 1];
			j--;
		}
		temp[j] = k;
		if (flag == true) {
			return true;
		}
	}
	return false;
}

void mergesort() {
	bool flag = false;
	for (int step = 2; step / 2 <= n; step *= 2) {
		if (step != 2 && isSame(temp, changed)) {
			flag = true;
		}
		for (int i = 0; i < n; i += step) {
			sort(temp + i, temp + min(n, i + step));
		}
		if (flag) {
			showArray(temp);
			return;
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &origin[i]);
		temp[i] = origin[i];
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &changed[i]);
	}
	if (insertion()) {
		printf("Insertion Sort\n");
		showArray(temp);
	} else {
		printf("Merge Sort\n");
		for (int i = 0; i < n; i++) {
			temp[i] = origin[i];
		}
		mergesort();
	}
	return 0;
}
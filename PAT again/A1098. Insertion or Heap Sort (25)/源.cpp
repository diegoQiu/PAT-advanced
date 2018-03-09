#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 111;
int origin[maxn], tempOri[maxn], changed[maxn];
int n;
bool isSame(int a[], int b[]) {
	for (int i = 1; i <= n; i++) {
		if (a[i] != b[i])
			return false;
	}
	return true;
}

void showArray(int a[]) {
	for (int i = 1; i <= n; i++) {
		printf("%d", a[i]);
		if (i < n)
			printf(" ");
	}
}

bool insertion() {
	bool flag = false;
	for (int i = 2; i <= n; i++) {
		if (i != 2 && isSame(tempOri, changed)) {
			flag = true;
		}
		sort(tempOri+1, tempOri + i + 1);
		if (flag)
			return flag;
	}
	return false;
}

void adjustDown(int low,int high) {
	int i = low;
	int j = 2 * i;
	while (j <= high) {
		if (j+1<=high&&tempOri[j] < tempOri[j + 1]) {
			j++;
		}
		if (tempOri[i] < tempOri[j]) {
			swap(tempOri[j], tempOri[i]);
			i = j;
			j = i * 2;;
		}
		else {
			break;
		}
	}
}
void heapsort() {
	bool flag = false;
	for (int i = n/2; i >= 1; i--) {
		adjustDown(i, n);
	}
	for (int i = n; i > 1; i--) {
		if (i != n && isSame(tempOri, changed)) {
			flag = true;
		}
		swap(tempOri[i], tempOri[1]);
		adjustDown(1, i - 1);
		if (flag == true) {
			showArray(tempOri);
			return;
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &origin[i]);
		tempOri[i] = origin[i];
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &changed[i]);
	}
	if (insertion()) {
		cout << "Insertion Sort" << endl;
		showArray(tempOri);
	}
	else {
		printf("Heap Sort\n");
		for (int i = 1; i <= n; i++) {
			tempOri[i] = origin[i];
		}
		heapsort();
	}
	return 0;
}
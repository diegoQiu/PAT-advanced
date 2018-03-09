#include<iostream>
#include<string>
#include<cstring>
using namespace std;
bool hashTable[280] = { false };
int main() {
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] >= 'A'&&a[i] <= 'Z') {
			a[i] = a[i] - 'A' + 'a';
		}
		hashTable[a[i]] = true;
	}
	for (int i = 0; i < b.length(); i++) {
		if (b[i] >= 'A'&&b[i] <= 'Z') {
			int low = b[i] - 'A' + 'a';
			if (hashTable[low] == false && hashTable['+'] == false)
				printf("%c", b[i]);
		} else if (hashTable[b[i]] == false)
			printf("%c", b[i]);
	}
	return 0;
}
#include<iostream>
#include<string>
using namespace std;
int hashTable[260];
int main() {
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < a.length(); i++) {
		hashTable[a[i]]++;
	}
	int lack = 0;
	for (int i = 0; i < b.length(); i++) {
		if (hashTable[b[i]] > 0)
			hashTable[b[i]]--;
		else
			lack++;
	}
	if (lack == 0)
		printf("Yes %d", a.length() - b.length());
	else
		printf("No %d", lack);
}
#include<iostream>
#include<string>
using namespace std;
bool hashTable[280];
int main() {
	string a, b;
	getline(cin, a);
	getline(cin, b);
	for (int i = 0; i < b.length(); i++) {
		hashTable[b[i]] = true;
	}
	for (int i = 0; i < a.length(); i++) {
		if (hashTable[a[i]] == true)
			continue;
		else
			printf("%c", a[i]);
	}
	return 0;
}
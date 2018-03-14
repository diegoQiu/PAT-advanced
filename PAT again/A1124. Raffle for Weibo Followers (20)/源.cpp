#include<iostream>
#include<string>
#include<map>
using namespace std;

int M, N, S;
string str[1001];
map<string, bool> haveWon;
int main() {
	cin >> M >> N >> S;
	for (int i = 1; i <= M; i++) {
		cin >> str[i];
	}
	if (M < S) {
		printf("Keep going...\n");
		return 0;
	}
	for (int i = S; i <= M; ) {
		if (haveWon[str[i]] == false) {
			cout << str[i] << endl;
			haveWon[str[i]] = true;
			i += N;
		} else
			i++;
	}
	return 0;
}
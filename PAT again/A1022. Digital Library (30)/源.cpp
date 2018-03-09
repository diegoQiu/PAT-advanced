#include<iostream>
#include<set>
#include<map>
#include<string>	
using namespace std;

map<string, set<int> > mpTitle, mpAuthor, mpKey, mpPub, mpYear;

void check(map<string, set<int> >& mp, string& str) {
	if (mp.find(str) == mp.end()) {
		printf("Not Found\n");
	} else {
		for (auto it = mp[str].begin(); it != mp[str].end(); it++) {
			printf("%07d\n", *it);
		}
	}
}
int main() {
	int n, m, id, type;
	string title, author, key, pub, year;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &id);
		getchar();
		getline(cin, title);
		mpTitle[title].insert(id);
		getline(cin, author);
		mpAuthor[author].insert(id);
		while (cin >> key) {
			mpKey[key].insert(id);
			char c = getchar();
			if (c == '\n')
				break;
		}
		getline(cin, pub);
		mpPub[pub].insert(id);
		getline(cin, year);
		mpYear[year].insert(id);
	}
	string temp;
	cin >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d: ", &type);
		getline(cin, temp);
		cout << type << ": " << temp << endl;
		if (type == 1) {
			check(mpTitle, temp);
		} else if (type == 2) {
			check(mpAuthor, temp);
		} else if (type == 3) {
			check(mpKey, temp);
		} else if (type == 4) {
			check(mpPub, temp);
		} else
			check(mpYear, temp);
	}
	return 0;
}
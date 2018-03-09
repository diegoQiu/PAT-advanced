#include<iostream>
#include<queue>
using namespace std;
int N, M, L, T;
struct Node {
	int x, y, z;
}node;

int G[1290][130][61];
bool inq[1290][130][61] = { false };
int X[6] = { 0,0,0,0,1,-1 };
int Y[6] = { 0,0,1,-1,0,0 };
int Z[6] = { 1,-1,0,0,0,0 };

bool judge(int x, int y, int z) {
	if (x >= N || x < 0 || y >= M || y < 0 || z >= L || z < 0)
		return false;
	if (G[x][y][z] == 0 || inq[x][y][x] == true)
		return false;
	return true;
}

int bfs(int x, int y, int z) {
	int tol = 0;
	queue<Node> q;
	node.x = x, node.y = y, node.z = z;
	q.push(node);
	inq[x][y][z] = true;
	while (!q.empty()) {
		Node top = q.front();
		q.pop();
		tol++;
		for (int i = 0; i < 6; i++) {
			int newx = top.x + X[i];
			int newy = top.y + Y[i];
			int newz = top.z + Z[i];
			if (judge(newx, newy, newz)) {
				node.x = newx;
				node.y = newy;
				node.z = newz;
				q.push(node);
				inq[newx][newy][newz] = true;
			}
		}
	}
	if (tol >= T)
		return tol;
	else
		return 0;
}

int main() {
	cin >> N >> M >> L >> T;
	for (int z = 0; z < L; z++) {
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				scanf("%d", &G[x][y][z]);
			}
		}
	}
	int ans = 0;
	for (int z = 0; z < L; z++) {
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				if (G[x][y][z] == 1 && inq[x][y][z] == false) {
					ans += bfs(x, y, z);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
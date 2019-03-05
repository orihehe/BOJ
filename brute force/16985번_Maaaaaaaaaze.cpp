/*
BOJ 16985 - Maaaaaaaaaze
https://www.acmicpc.net/problem/16985
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define INF 2000000000
using namespace std;

/* 🐣🐥 */
int maze[5][5][5];
int xgo[6] = { 0,0,0,0,1,-1 };
int ygo[6] = { 1,-1,0,0,0,0 };
int zgo[6] = { 0,0,1,-1,0,0 };
int b[5][5][5], mn = INF;
bool use[5], visited[5][5][5];
struct loc {
	int x, y, z;
};
int bfs() { // 가능한지
	queue<loc> q;
	q.push({ 0,0,0 });
	memset(visited, false, sizeof(visited));
	visited[0][0][0] = true;
	bool suc = false;
	int s = 1, cnt = 0;
	while (!q.empty()) {
		if (s == 0) {
			s = q.size();
			cnt++;
		}
		loc cur = q.front();
		q.pop();
		if (cur.x == 4 && cur.y == 4 && cur.z == 4) {
			suc = true;
			break;
		}
		for (int i = 0; i < 6; i++) {
			int nx = cur.x + xgo[i], ny = cur.y + ygo[i], nz = cur.z + zgo[i];
			if (nx < 0 || ny < 0 || nz < 0 || nx >= 5 || ny >= 5 || nz >= 5) continue;
			if (!visited[nx][ny][nz] && maze[nx][ny][nz]) {
				visited[nx][ny][nz] = true;
				q.push({ nx,ny,nz });
			}
		}
		s--;
	}
	if (suc)
		return cnt;
	else return INF;
}
void rot(int cur, int l) {
	int tmp[5][5];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			tmp[i][j] = b[cur][j][4 - i];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			b[cur][i][j] = tmp[i][j];
			maze[l][i][j] = b[cur][i][j];
		}
	}
}
void go(int cur) {
	if (cur == 5) {
		if (maze[0][0][0] && maze[4][4][4])
			mn = min(mn, bfs());
		return;
	}
	for (int i = 0; i < 5; i++) {
		if (!use[i]) {
			use[i] = true;
			for (int j = 0; j < 4; j++) {
				rot(i, cur);
				go(cur + 1);
			}
			use[i] = false;
		}
	}
}
int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				scanf("%d", &b[i][j][k]);
			}
		}
	}
	go(0);
	if (mn == INF) printf("-1");
	else printf("%d", mn);

	return 0;
}
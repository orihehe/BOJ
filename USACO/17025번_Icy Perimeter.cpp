/*
BOJ 17025 - Icy Perimeter
https://www.acmicpc.net/problem/17025
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
char b[1002][1002];
bool visited[1002][1002];
int rgo[4] = { 0,1,0,-1 }, cgo[4] = { 1,0,-1,0 };
int para, cnt, n, ap = 0, ac = 0;
void dfs(int r, int c) {
	visited[r][c] = true;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nr = r + rgo[i], nc = c + cgo[i];
		if (visited[nr][nc]) continue;
		if (b[nr][nc] == '.') {
			para++;
			continue;
		}
		dfs(nr, nc);
	}
}
int main() {
	scanf("%d", &n);
	memset(b, '.', sizeof(b));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %c", &b[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visited[i][j] && b[i][j] == '#') {
				para = cnt = 0;
				dfs(i, j);
				if (cnt >= ac) {
					if (cnt == ac) {
						ap = min(ap, para);
					}
					else ap = para;
					ac = cnt;
				}
			}
		}
	}
	printf("%d %d", ac, ap);

	return 0;
}
/*
BOJ 5212 - 지구 온난화
https://www.acmicpc.net/problem/5212
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
int main() {
	int r, c, ur, uc, dr, dc;
	int rgo[4] = { 1,0,-1,0 }, cgo[4] = { 0,1,0,-1 };
	char st[12][12];
	char ans[12][12];
	memset(st, '.', sizeof(st));
	scanf("%d %d", &r, &c);
	dr = dc = 1, ur = r, uc = c;
	for (int i = 1; i <= r; i++) {
		scanf("%s", st[i] + 1);
		st[i][c + 1] = '.';
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nr = rgo[k] + i, nc = cgo[k] + j;
				cnt += st[nr][nc] == '.';
			}
			if (cnt >= 3) ans[i][j] = '.';
			else ans[i][j] = st[i][j];
			if (ans[i][j] == 'X') {
				dr = max(dr, i), dc = max(dc, j);
				ur = min(ur, i), uc = min(uc, j);
			}
		}
	}
	for (int i = ur; i <= dr; i++) {
		for (int j = uc; j <= dc; j++)
			printf("%c", ans[i][j]);
		printf("\n");
	}

	return 0;
}
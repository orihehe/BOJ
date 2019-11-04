/*
BOJ 9518 - 로마 카톨릭 미사
https://www.acmicpc.net/problem/9518
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int rgo[8] = { 1,1,1,-1,-1,-1,0,0 }, cgo[8] = { -1,0,1,-1,0,1,-1,1 };
char st[51][51];
int main() {
	int r, c, ans = 0, cnt = 0;
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) scanf("%s", st[i]);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (st[i][j] == 'o') {
				for (int k = 0; k < 8; k++) {
					int nr = i + rgo[k], nc = j + cgo[k];
					if (nr < 0 || nc < 0 || nr >= r || nc >= c)continue;
					if (st[nr][nc] == 'o') cnt++;
				}
			}
			else {
				int tmp = 0;
				for (int k = 0; k < 8; k++) {
					int nr = i + rgo[k], nc = j + cgo[k];
					if (nr < 0 || nc < 0 || nr >= r || nc >= c)continue;
					if (st[nr][nc] == 'o') tmp++;
				}
				ans = max(ans, tmp);
			}
		}
	}
	printf("%d", ans + cnt / 2);

	return 0;
}
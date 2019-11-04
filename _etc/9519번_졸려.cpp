/*
BOJ 9519 - 졸려
https://www.acmicpc.net/problem/9519
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
char st[1001], ans[1001];
int loc[1001][1001];
int go[1001];
int main() {
	int n, len;
	scanf("%d %s", &n, st);
	len = strlen(st);
	int md = 0;
	for (int i = 0; i < len; i += 2)
		go[i] = i / 2;
	for (int i = 1; i < len; i += 2)
		go[i] = len - i / 2 - 1;
	for (int i = 1; i < len; i++) {
		int tmp = i;
		for (int j = 0;; j++) {
			md = max(md, j);
			if (j != 0 && tmp == i && md <= j) break;
			loc[j][tmp] = i;
			tmp = go[tmp];
		}
	}
	for (int i = 0; i < len; i++) {
		ans[i] = st[loc[n % md][i]];
	}
	printf("%s", ans);

	return 0;
}
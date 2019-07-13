/*
BOJ 2401 - 최대 문자열 붙여넣기
https://www.acmicpc.net/problem/2401
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
char st[100001], my[500][10001];
int len[500], fail[10001], n, ml, dp[100001];
bool can[500][100001];
int dfs(int cur) {
	if (ml == cur) return 0;
	if (dp[cur] != -1) return dp[cur];
	int ret = dfs(cur + 1);
	for (int i = 0; i < n; i++) {
		if (can[i][cur]) ret = max(ret, dfs(cur + len[i]) + len[i]);
	}
	return dp[cur] = ret;
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%[^\n]", st);
	scanf("%d", &n);
	ml = strlen(st);
	for (int o = 0; o < n; o++) {
		getchar();
		scanf("%[^\n]", my[o]);
		len[o] = strlen(my[o]);
		memset(fail, 0, sizeof(fail));
		for (int i = 1, j = 0; i < len[o]; i++) {
			while (j > 0 && my[o][i] != my[o][j]) j = fail[j - 1];
			if (my[o][i] == my[o][j]) fail[i] = ++j;
		}
		for (int i = 0, j = 0; i < ml; i++) {
			while (j > 0 && st[i] != my[o][j]) j = fail[j - 1];
			if (st[i] == my[o][j]) {
				if (j == len[o] - 1) {
					can[o][i - len[o] + 1] = true;
					j = fail[j];
				}
				else j++;
			}
		}
	}
	printf("%d", dfs(0));

	return 0;
}
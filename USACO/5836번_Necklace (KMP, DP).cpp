/*
BOJ 5836 - Necklace
https://www.acmicpc.net/problem/5836
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#define INF 987654321
using namespace std;

/* 🐣🐥 */
char st[10001], my[1001];
int fail[1001], n, m, dp[10001][1001], go[1001][26];
int dfs(int i, int j) {
	if (i == n) return 0;
	if (dp[i][j] != INF) return dp[i][j];
	int ret = dfs(i + 1, j) + 1; // 지운거
	int tt = j;
	if (st[i] != my[tt]) tt = go[tt][st[i] - 'a'];
	if (st[i] == my[tt]) {
		if (tt != m - 1)
			ret = min(dfs(i + 1, tt + 1), ret);
	}
	else ret = min(dfs(i + 1, tt), ret);
	return dp[i][j] = ret;
}
int main() {
	scanf("%s %s", st, my);
	n = strlen(st);
	m = strlen(my);
	for (int i = 0; i < n; i++) {
		fill(dp[i], dp[i] + m, INF);
	}
	for (int i = 1, j = 0; i < m; i++) {
		while (j > 0 && my[i] != my[j]) j = fail[j - 1];
		if (my[i] == my[j]) fail[i] = ++j;
	}

	for (int i = 1; i < m; i++) {
		for (int j = 0; j < 26; j++)
			go[i][j] = go[fail[i - 1]][j];
		go[i][my[fail[i - 1]] - 'a'] = fail[i - 1];
	}
	printf("%d", dfs(0, 0));

	return 0;
}
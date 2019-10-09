/*
BOJ 2662 - 기업투자
https://www.acmicpc.net/problem/2662
*/
#include <cstdio>
#include <cstring>
using namespace std;

/* 🐣🐥 */
int dp[20][301], arr[20][301], p[20][301];
int n, m;
int dfs(int cur, int w) {
	if (w <= 0 || cur == m) return 0;
	if (dp[cur][w] != -1) return dp[cur][w];
	int ret = 0, pp = 0, tmp;
	for (int i = w; i >= 0; i--) {
		tmp = dfs(cur + 1, i) + arr[cur][w - i];
		if (ret < tmp) {
			ret = tmp;
			pp = w - i;
		}
	}
	p[cur][w] = pp;
	return dp[cur][w] = ret;
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%*d");
		for (int j = 0; j < m; j++) scanf("%d", &arr[j][i]);
	}
	printf("%d\n", dfs(0, n));
	for (int i = 0; i < m; i++) {
		printf("%d ", p[i][n]);
		n -= p[i][n];
	}

	return 0;
}
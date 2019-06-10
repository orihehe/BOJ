/*
BOJ 17240 - Team Selection
https://www.acmicpc.net/problem/17240

dp[이미 선택된 역할 비트][인덱스]
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
int arr[20001][5];
int dp[32][20001], n;
int dfs(int num, int cur) {
	if (num == 31) return 0;
	if (cur == n) return 0;
	if (dp[num][cur] != -1) return dp[num][cur];
	int ret = dfs(num, cur + 1);
	for (int i = 0; i < 5; i++) {
		int tmp = 1 << i;
		if (num & tmp) continue;
		ret = max(ret, arr[cur][i] + dfs(num | tmp, cur + 1));
	}
	return dp[num][cur] = ret;
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 5; j++)
			scanf("%d", &arr[i][j]);
	printf("%d", dfs(0, 0));

	return 0;
}
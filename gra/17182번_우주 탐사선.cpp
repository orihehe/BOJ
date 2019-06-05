/*
BOJ 17182 - 우주 탐사선
https://www.acmicpc.net/problem/17182

플로이드로 i->j의 최단거리를 구해둔 뒤 완탐
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#define INF 987654321
using namespace std;

/* 🐣🐥 */
int arr[11][11];
int dp[11][1 << 10];
int n, k;
int dfs(int cur, int mm) {
	if (mm == (1 << n) - 1) 
		return 0;
	if (dp[cur][mm] != -1) return dp[cur][mm];
	int ret = INF;
	for (int i = 0; i < n; i++) {
		if ((mm & (1 << i)) == 0)
			ret = min(ret, dfs(i, mm + (1 << i)) + arr[cur][i]);
	}
	return dp[cur][mm] = ret;
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
	printf("%d", dfs(k, 1 << k));

	return 0;
}
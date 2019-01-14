/*
BOJ 14925 (https://www.acmicpc.net/problem/14925)
현재 0이고 dp[i - 1][j],dp[i][j - 1],dp[i - 1][j - 1]에서 x크기의 정사각형을 만들 수 있다면
현재 위치에서 x+1크기의 정사각형을 만들 수 있다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int dp[1001][1001];
int main() {
	int m, n, maxS=0, x;
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &x); 
			if (x == 0) {
				dp[i][j] = min({ dp[i - 1][j],dp[i][j - 1],dp[i - 1][j - 1] }) + 1;
			}
			maxS = max(maxS, dp[i][j]);
		}
	}
	printf("%d", maxS);

	return 0;
}
/*
BOJ 16399 - 드라이브
https://www.acmicpc.net/problem/16399

dp[현재위치][남은 연료]
*/
#include <cstdio>
#include <algorithm>
#define ll long long
#define INF 5000000001
using namespace std;

/* 🐣🐥 */
int loc[1002], p[1002], e, d, n, c;
ll dp[1002][502];
int main() {
	scanf("%d %d %d %d", &c, &e, &d, &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &loc[i]);
		d -= loc[i];
	}
	loc[n + 1] = d;
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);

	for (int i = 0; i <= n + 1; i++)
		fill(dp[i], dp[i] + c + 1, INF);

	dp[0][c] = 0;
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= c; j++) {
			// 남은 연료로 다음 주유소까지 갈 수 있다면
			if (j - e * loc[i + 1] >= 0) {
				dp[i + 1][j - e * loc[i + 1]] =
					min(dp[i + 1][j - e * loc[i + 1]], dp[i][j]);
			}
			// 여기서 충전하는 것이 이득인지 판별
			if (j + 1 <= c) {
				dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + p[i]);
			}
		}
	}
	// 도착지의 충전비는 0이므로 c에 자동으로 결과가 들어있다.
	printf("%lld", dp[n + 1][c] >= INF ? -1 : dp[n + 1][c]);

	return 0;
}
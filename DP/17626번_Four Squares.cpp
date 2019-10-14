/*
BOJ 17626 - Four Squares
https://www.acmicpc.net/problem/17626
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int wprhq[250], dp[50001];
int main() {
	for (int i = 1; i < 250; i++)
		wprhq[i] = i * i;
	int n;
	scanf("%d", &n);
	fill(dp, dp + n + 1, 50001);
	dp[0] = 0;
	for (int i = 1; i < 250; i++) {
		for (int j = wprhq[i]; j <= n; j++) {
			dp[j] = min(dp[j], dp[j - wprhq[i]] + 1);
		}
	}
	printf("%d", dp[n]);

	return 0;
}
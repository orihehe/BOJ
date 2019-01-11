/*
BOJ 15993 (https://www.acmicpc.net/problem/15993)
*/
#include <cstdio>
#define mod 1000000009
using namespace std;

int dp[2][100001];
int main() {
	int t, n;
	dp[1][1] = dp[1][2] = dp[1][3] = 1;
	for (int i = 1; i <= 100000; i++) {
		for (int j = 1; j <= 3; j++) {
			dp[0][i] = (dp[1][i - j] + dp[0][i]) % mod;
			dp[1][i] = (dp[0][i - j] + dp[1][i]) % mod;
		}
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%d %d\n", dp[1][n], dp[0][n]);
	}

	return 0;
}
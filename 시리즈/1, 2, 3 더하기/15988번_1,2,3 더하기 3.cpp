/*
BOJ 15988 (https://www.acmicpc.net/problem/15988)
*/
#include <cstdio>
#define mod 1000000009
using namespace std;

int dp[1000001];
int main() {
	int t, n;
	dp[1] = dp[2] = dp[3] = 1;
	for (int i = 1; i <= 1000000; i++) {
		for (int j = 1; j <= 3; j++) {
			dp[i] = (dp[i] + dp[i - j]) % mod;
		}
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}

	return 0;
}
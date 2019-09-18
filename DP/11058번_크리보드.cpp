/*
BOJ 11058 - 크리보드
https://www.acmicpc.net/problem/11058
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
long long dp[101];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = i + 3; j <= n; j++) 
			dp[j] = max(dp[j], dp[i] * (j - i - 1));
		dp[i + 1] = max(dp[i + 1], dp[i] + 1);
	}
	printf("%lld", dp[n]);

	return 0;
}
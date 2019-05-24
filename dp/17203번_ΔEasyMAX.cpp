/*
BOJ 17203 - ∑|ΔEasyMAX|
https://www.acmicpc.net/problem/17203

부분합으로 구해보자
*/
#include <cstdio>
#include <cmath>
using namespace std;

/* 🐣🐥 */
int dp[1001], arr[1001];
int main() {
	int n, q, a, b;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + abs(arr[i] - arr[i - 1]);
	}
	while (q--) {
		scanf("%d %d", &a, &b);
		if (a == b) printf("0\n");
		else printf("%d\n", dp[b] - dp[a]);
	}

	return 0;
}
/*
BOJ 2410 - 2의 멱수의 합
https://www.acmicpc.net/problem/2410
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int arr[20], dp[1000001][20];
int main() {
	int t = 1;
	for (int i = 0; i < 20; i++) {
		arr[i] = t;
		dp[0][i] = 1;
		t *= 2;
	}
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
		for (int j = 1; j < 20; j++) {
			dp[i][j] = dp[i][j - 1];
			if (arr[j] <= i)
				dp[i][j] = (dp[i][j] + dp[i - arr[j]][j]) % 1000000000;
		}
	}
	printf("%d", dp[n][19]);

	return 0;
}
/*
BOJ 10019 - Sabotage
https://www.acmicpc.net/problem/10019

(dp[n]-dp[j]+dp[i])/(n-(j-i)) <= x
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int dp[100001];
int main() {
	int n, x;
	double mid, l, r, mn;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		dp[i] = dp[i - 1] + x;
	}
	l = 1, r = 10000;
	for (int j = 0; j < 100; j++) {
		mid = (l + r) / 2;
		mn = 10000;
		bool suc = false;
		for (int i = 2; i <= n - 1; i++) {
			mn = min(mn, dp[i - 1] - mid * (i - 1));
			if (mn + dp[n] - mid * n <= dp[i] - mid * i) {
				suc = true;
				break;
			}
		}
		if (suc)
			r = mid;
		else l = mid;
	}
	printf("%.3lf", r);

	return 0;
}
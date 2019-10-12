/*
BOJ 17528 - Two Machines
https://www.acmicpc.net/problem/17528
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 62501
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
pii dp[MAX];
int main() {
	int n, a, b;
	scanf("%d", &n);
	dp[0] = { 0,0 };
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		for (int j = MAX - 1; j >= 0; j--) {
			if (j - a >= 0 && dp[j - a].second == i) {
				if (dp[j].second == i)
					dp[j] = { min(dp[j - a].first, dp[j].first + b),i + 1 };
				else dp[j] = { dp[j - a].first,i + 1 };
			}
			else if (dp[j].second == i)
				dp[j] = { dp[j].first + b,i + 1 };
		}
	}
	int ans = 100000;
	for (int i = 0; i < MAX; i++) {
		if (dp[i].second == n) ans = min(ans, max(i, dp[i].first));
	}
	printf("%d", ans);

	return 0;
}
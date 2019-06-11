/*
BOJ 17243 - Almost-K Increasing Subsequence
https://www.acmicpc.net/problem/17243

dp[k개수][인덱스]
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
int arr[501], dp[501][501];
int main() {
	int n, ans = 0, m;
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (int i = 0; i < n; i++) {
		int tmp = 0, sz;
		sz = min(i, m);
		for (int k = 0; k <= sz; k++) {
			tmp = 0;
			for (int j = 0; j < i; j++) {
				if (arr[j] > arr[i]) {
					if (k != 0)
						tmp = max(tmp, dp[k - 1][j]);
				}
				else tmp = max(tmp, dp[k][j]);
			}
			dp[k][i] = tmp + 1;
			ans = max(ans, dp[k][i]);
		}
	}
	printf("%d", ans);

	return 0;
}
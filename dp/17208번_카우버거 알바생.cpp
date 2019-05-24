/*
BOJ 17208 - 카우버거 알바생
https://www.acmicpc.net/problem/17208

냅색, 제공한 dp[치즈버거][감자튀김] 에 최대 주문 개수를 저장해둔다. 
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
pii arr[101];
int dp[301][301];
int main() {
	int n, m, k, ans = 0;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++) scanf("%d %d", &arr[i].first, &arr[i].second);

	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int x = m - arr[i].first; x >= 0; x--) {
			for (int y = k - arr[i].second; y >= 0; y--) {
				if (dp[x][y] != -1)
					dp[x + arr[i].first][y + arr[i].second] =
					max(dp[x + arr[i].first][y + arr[i].second], dp[x][y] + 1);
				ans = max(ans, dp[x + arr[i].first][y + arr[i].second]);
			}
		}
	}
	printf("%d", ans);

	return 0;
}
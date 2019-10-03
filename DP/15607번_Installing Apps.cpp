/*
BOJ 15607 - Installing Apps
https://www.acmicpc.net/problem/15607

특정 어플을 설치할 것이라고 한다면
설치 순서는 (a1,a2) (b1,b2)일 때 a2+b1 < b2+a1 => a2-a1 < b2-a1
즉 x2-x1이 작은 어플부터 설치하는 것이 이득이다.
따라서 이 기준으로 정렬 후 냅색dp를 돌려준다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
int dp[501][10001];
vector<int> ans;
struct info {
	int first, second, idx;
} arr[501];
int main() {
	int n, c;
	scanf("%d %d", &n, &c);
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &arr[i].first, &arr[i].second);
		arr[i].idx = i;
	}
	sort(arr + 1, arr + n + 1, [](info a, info b) {
		return a.first - a.second > b.first - b.second;
	});
	int now = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= c - arr[i].first; j++) {
			if (j + arr[i].second > c) break;
			if (dp[i - 1][j] == -1) continue;
			dp[i][j + arr[i].second] =
				max(dp[i][j + arr[i].second], dp[i - 1][j] + 1);
		}
		for (int j = 0; j <= c; j++)
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		if (i == n) {
			int mx = 0;
			for (int j = c; j >= 0; j--)
				if (dp[i][j] > mx)
					mx = dp[i][j], now = j;
		}
	}
	if (now == -1) return !printf("0");
	for (int i = n; i >= 1; i--) {
		if (now - arr[i].second < 0) continue;
		if (dp[i][now] == dp[i - 1][now - arr[i].second] + 1) {
			now -= arr[i].second;
			ans.push_back(arr[i].idx);
		}
	}
	printf("%d\n", ans.size());
	reverse(ans.begin(), ans.end());
	for (int v : ans) printf("%d ", v);

	return 0;
}
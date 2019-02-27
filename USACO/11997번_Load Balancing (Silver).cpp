/*
BOJ 11997 (https://www.acmicpc.net/problem/11997)

좌표압축 후 dp배열에 부분합을 저장, 각 울타리 별로 4개 범위의 점 개수를 세서 구해준다.
*/
#include <cstdio>
#include <algorithm>
#include <set>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
set<int> X, Y;
set<int> ::iterator iterX, iterY;
int arr[1002][1002], dp[1002][1002];
pii loc[1001];
int main() {
	int n, a, b, a1, a2, a3, a4, ans = 987654321;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		X.insert(a);
		Y.insert(b);
		loc[i] = { a,b };
	}
	sort(loc, loc + n);
	a = b = 1;
	for (iterX = X.begin(); iterX != X.end(); iterX++) {
		for (iterY = Y.begin(); iterY != Y.end(); iterY++) {
			int idx = lower_bound(loc, loc + n, pii(*iterX, *iterY)) - loc;
			if (loc[idx].first == *iterX && loc[idx].second == *iterY) {
				arr[a][b] = 1;
			}
			b++;
		}
		a++;
		b = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = arr[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a1 = dp[n][n] - dp[n - i][n] - dp[n][n - j] + dp[n - i][n - j];
			a2 = dp[n][n - j] - dp[n - i][n - j];
			a3 = dp[n - i][n] - dp[n - i][n - j];
			a4 = dp[n - i][n - j];
			ans = min(ans, max({ a1,a2,a3,a4 }));
		}
	}
	printf("%d", ans);

	return 0;
}
/*
BOJ 11873 - 최대 직사각형
https://www.acmicpc.net/problem/11873
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int arr[2001][2001], ans;
void dq(int e, int l, int r) {
	if (l == r) {
		ans = max(ans, arr[e][l]);
		return;
	}
	int mid = (l + r) / 2;
	dq(e, l, mid);
	dq(e, mid + 1, r);
	int s = mid, mn = 2001;
	for (int i = mid; i <= r; i++) {
		while (s > l && arr[e][s - 1] > arr[e][i]) {
			mn = min(mn, arr[e][--s]);
			ans = max(ans, mn * (i - s));
		}
		mn = min(mn, arr[e][i]);
		ans = max(ans, mn * (i - s + 1));
	}
	while (s > l) {
		mn = min(mn, arr[e][--s]);
		ans = max(ans, mn * (r - s + 1));
	}
}
int main() {
	int n, m;
	while (scanf("%d %d", &n, &m)) {
		if (n == 0 && m == 0) break;
		ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &arr[i][j]);
		for (int i = 0; i < n; i++) {
			dq(i, 0, m - 1);
			for (int j = 0; j < m; j++)
				if (arr[i + 1][j]) arr[i + 1][j] += arr[i][j];
		}
		printf("%d\n", ans);
	}

	return 0;
}
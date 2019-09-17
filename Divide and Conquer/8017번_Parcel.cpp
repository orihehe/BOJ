/*
BOJ 8017 - Parcel
https://www.acmicpc.net/problem/8017

열마다 히스토그램에서 가장 큰 직사각형(BOJ 6549) 문제를 풀어준다.
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
	int n;
	scanf("%d", &n);
	ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			arr[i][j] = !arr[i][j];
		}
	for (int i = 0; i < n; i++) {
		dq(i, 0, n - 1);
		for (int j = 0; j < n; j++)
			if (arr[i + 1][j]) arr[i + 1][j] += arr[i][j];
	}
	printf("%d\n", ans);

	return 0;
}
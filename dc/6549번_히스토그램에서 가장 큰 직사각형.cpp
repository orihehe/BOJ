/*
BOJ 6549 - 히스토그램에서 가장 큰 직사각형
https://www.acmicpc.net/problem/6549

각 구간에서 mid에서부터 큰 높이를 높이로 두고 양옆으로 퍼져나간다.
*/
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

/* 🐣🐥 */
ll arr[100001], mx;
void dq(int l, int r) {
	if (l == r) {
		mx = max(mx, arr[l]);
		return;
	}
	int mid = (l + r) / 2;
	ll ans = 0, h;
	dq(l, mid);
	dq(mid + 1, r);
	ll lp = mid, rp = mid + 1;
	while (lp >= l || rp <= r) {
		if (rp>r || (lp >= l && arr[lp] > arr[rp])) {
			h = arr[lp];
		}
		else {
			h = arr[rp];
		}
		while (lp >= l && arr[lp] >= h) lp--;
		while (rp <= r && arr[rp] >= h) rp++;
		ans = h * (rp - lp-1);
		mx = max(ans, mx);
	}
}
int main() {
	int n;
	while (scanf("%d", &n)) {
		if (n == 0) break;
		mx = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &arr[i]);
		}
		dq(1, n);
		printf("%lld\n", mx);
	}

	return 0;
}
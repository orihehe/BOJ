/*
BOJ 2352 - 반도체 설계
https://www.acmicpc.net/problem/2352
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int arr[40001], tree[131072];
void update(int idx, int s, int e, int k, int val) {
	if (k < s || k > e) return;
	if (s == e) {
		tree[idx] = val;
		return;
	}
	update(idx * 2, s, (s + e) / 2, k, val);
	update(idx * 2 + 1, (s + e) / 2 + 1, e, k, val);
	tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
}
int getMax(int idx, int s, int e, int l, int r) {
	if (e < l || s > r) return 0;
	if (l <= s && e <= r) return tree[idx];
	return max(getMax(idx * 2, s, (s + e) / 2, l, r),
		getMax(idx * 2 + 1, (s + e) / 2 + 1, e, l, r));
}
int main() {
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	for (int i = 1; i <= n; i++) {
		int mx = getMax(1, 1, n, 1, arr[i]) + 1;
		ans = max(ans, mx);
		update(1, 1, n, arr[i], mx);
	}
	printf("%d", ans);

	return 0;
}
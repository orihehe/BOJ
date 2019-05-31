/*
BOJ 2357 - 최솟값과 최댓값
https://www.acmicpc.net/problem/2357
*/
#include <cstdio>
#include <algorithm>
#define MAX 2000000000
using namespace std;

/* 🐣🐥 */
int xtree[262145], ntree[262145];
int n, q, a, b;
int minV(int idx, int s, int e, int l, int r) {
	if (r<s || l>e) return MAX;
	if (l <= s && e <= r) {
		return ntree[idx];
	}
	return min(minV(idx * 2, s, (s + e) / 2, l, r),
		minV(idx * 2 + 1, (s + e) / 2 + 1, e, l, r));
}
int maxV(int idx, int s, int e, int l, int r) {
	if (r<s || l>e) return 0;
	if (l <= s && e <= r) {
		return xtree[idx];
	}
	return max(maxV(idx * 2, s, (s + e) / 2, l, r),
		maxV(idx * 2 + 1, (s + e) / 2 + 1, e, l, r));
}
void update(int idx, int s, int e, int k, int val) {
	if (k<s || k>e) return;
	if (s==e) {
		xtree[idx] = ntree[idx] = val;
		return;
	}
	update(idx * 2, s, (s + e) / 2, k, val);
	update(idx * 2 + 1, (s + e) / 2 + 1, e, k, val);
	xtree[idx] = max(xtree[idx * 2], xtree[idx * 2 + 1]);
	ntree[idx] = min(ntree[idx * 2], ntree[idx * 2 + 1]);
}
int main() {
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		update(1, 1, n, i, a);
	}
	for (int i = 0; i < q; i++) {
		scanf("%d %d", &a, &b);
		printf("%d %d\n", minV(1, 1, n, a, b), maxV(1, 1, n, a, b));
	}

	return 0;
}
/*
BOJ 14458 - 소가 길을 건너간 이유 10
https://www.acmicpc.net/problem/14458
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

/* 🐣🐥 */
int A[100001], Aidx[100001], B[100001], Bidx[100001];
int num[100001], tree[262144];
void update(int idx, int s, int e, int l, int r, bool w) {
	if (e < l || s > r) return;
	if (l <= s && e <= r) {
		tree[idx]++;
		return;
	}
	update(idx * 2, s, (s + e) / 2, l, r, w);
	update(idx * 2 + 1, (s + e) / 2 + 1, e, l, r, w);
	if (w)
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}
int hap(int idx, int s, int e, int l, int r) {
	if (e < l || s > r) return 0;
	if (l <= s && e <= r) return tree[idx];
	return hap(idx * 2, s, (s + e) / 2, l, r)
		+ hap(idx * 2 + 1, (s + e) / 2 + 1, e, l, r);
}
int getPlus(int idx, int s, int e, int k, int nn) {
	if (k < s || k > e) return 0;
	nn += tree[idx];
	if (s == e) return nn;
	return getPlus(idx * 2, s, (s + e) / 2, k, nn)
		+ getPlus(idx * 2 + 1, (s + e) / 2 + 1, e, k, nn);
}
int main() {
	int n;
	ll tmp = 0, ans;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
		Aidx[A[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &B[i]);
		Bidx[B[i]] = i;
	}

	for (int i = n - 1; i >= 0; i--) {
		num[A[i]] = hap(1, 0, n - 1, 0, Bidx[A[i]]);
		update(1, 0, n - 1, Bidx[A[i]], Bidx[A[i]], true);
		tmp += num[A[i]];
	}
	ans = tmp;
	memset(tree, 0, sizeof(tree));
	for (int i = 0; i < n - 1; i++) {
		num[A[i]] += getPlus(1, 0, n - 1, Bidx[A[i]], 0);
		tmp += n - Bidx[A[i]] - 1 - num[A[i]];
		ans = min(ans, tmp);
		update(1, 0, n - 1, Bidx[A[i]], n - 1, false);
	}

	tmp = 0;
	memset(tree, 0, sizeof(tree));
	for (int i = n - 1; i >= 0; i--) {
		num[B[i]] = hap(1, 0, n - 1, 0, Aidx[B[i]]);
		update(1, 0, n - 1, Aidx[B[i]], Aidx[B[i]], true);
		tmp += num[B[i]];
	}
	ans = min(ans, tmp);
	memset(tree, 0, sizeof(tree));
	for (int i = 0; i < n - 1; i++) {
		num[B[i]] += getPlus(1, 0, n - 1, Aidx[B[i]], 0);
		tmp += n - Aidx[B[i]] - 1 - num[B[i]];
		ans = min(ans, tmp);
		update(1, 0, n - 1, Aidx[B[i]], n - 1, false);
	}

	printf("%lld", ans);

	return 0;
}
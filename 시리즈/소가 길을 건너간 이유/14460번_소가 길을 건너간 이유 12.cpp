/*
BOJ 14460 - 소가 길을 건너간 이유 12
https://www.acmicpc.net/problem/14460

분할정복으로 공장(BOJ 7578)문제 처럼 구하는 과정에서 왼쪽 구간을 모두 세그에 넣어두고,
왼쪽 구간 원소를 채울 땐 세그에서 빼주고, 
오른쪽 구간 원소를 채울 땐 현재 원소 값 +-k 초과인 개수를 세그에서 구해준다.
*/
#include <cstdio>
#include <algorithm>
#define ll long long
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
int A[100001], tree[262145];
pii B[100001], tmp[100001];
ll ans;
int n, k, x;
void update(int idx, int s, int e, int k, int val) {
	if (k < s || e < k) return;
	tree[idx]+=val;
	if (e == s) {
		tree[idx];
		return;
	}
	update(idx * 2, s, (s + e) / 2, k, val);
	update(idx * 2 + 1, (s + e) / 2 + 1, e, k, val);
}
int getCnt(int idx, int s, int e, int l, int r) {
	if (r<l || l>r) return 0;
	if (e<l || s > r) return 0;
	if (l <= s && e <= r) {
		return tree[idx];
	}
	return getCnt(idx * 2, s, (s + e) / 2, l, r)
		+ getCnt(idx * 2 + 1, (s + e) / 2 + 1, e, l, r);
}
void merge(int l, int r) {
	if (l == r) return;
	int mid = (l + r) / 2;
	merge(l, mid);
	merge(mid + 1, r);
	int ap = l, bp = mid + 1, tp = l;
	for (int i = l; i <= mid; i++) update(1, 1, n, B[i].second, 1);
	while (ap <= mid && bp <= r) {
		if (B[bp].first < B[ap].first) {
			ans += getCnt(1, 1, n, B[bp].second + k + 1, n);
			ans += getCnt(1, 1, n, 1, B[bp].second - k - 1);
			tmp[tp++] = B[bp++];
		}
		else {
			update(1, 1, n, B[ap].second, -1);
			tmp[tp++] = B[ap++];
		}
	}
	while (ap <= mid) {
		update(1, 1, n, B[ap].second, -1);
		tmp[tp++] = B[ap++];
	}
	while (bp <= r) {
		tmp[tp++] = B[bp++];
	}
	for (int i = l; i <= r; i++) B[i] = tmp[i];
}
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		A[x] = i;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		B[i] = { A[x], x };
	}
	merge(1, n);
	printf("%lld", ans);

	return 0;
}
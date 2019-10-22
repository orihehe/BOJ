/*
BOJ 5012 - 불만 정렬
https://www.acmicpc.net/problem/5012
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <functional>
#define ll long long
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
int tree[1 << 18];
int le[100001], ri[100001];
pii arr[100001];
void update(int idx, int s, int e, int k) {
	if (k<s || k>e) return;
	tree[idx]++;
	if (s == e) return;
	update(idx * 2, s, (s + e) / 2, k);
	update(idx * 2 + 1, (s + e) / 2 + 1, e, k);
}
int hap(int idx, int s, int e, int l, int r) {
	if (e < l || r < s) return 0;
	if (l <= s && e <= r) return tree[idx];
	return hap(idx * 2, s, (s + e) / 2, l, r) +
		hap(idx * 2 + 1, (s + e) / 2 + 1, e, l, r);
}
int main() {
	int n, x;
	ll ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		arr[i] = { x,i };
	}
	sort(arr, arr + n, greater<pii>());
	for (int i = 0; i < n; i++) {
		le[arr[i].second] = hap(1, 0, n - 1, 0, arr[i].second);
		update(1, 0, n - 1, arr[i].second);
	}
	memset(tree, 0, sizeof(tree));
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		ri[arr[i].second] = hap(1, 0, n - 1, arr[i].second, n - 1);
		update(1, 0, n - 1, arr[i].second);
	}
	for (int i = 0; i < n; i++)
		ans += (ll)le[i] * ri[i];
	printf("%lld", ans);

	return 0;
}
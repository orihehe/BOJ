/*
BOJ 14449 - Balanced Photo
https://www.acmicpc.net/problem/14449

큰 수부터 넣으면서 양 옆 구간의 나보다 큰 수 개수를 찾아 계산
*/
#include <cstdio>
#include <algorithm>
#include <functional>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
int tree[262145];
pii arr[100001];
void update(int idx, int s, int e, int k) {
	if (k<s || k>e)return;
	tree[idx]++;
	if (s == e)return;
	update(idx * 2, s, (s + e) / 2, k);
	update(idx * 2 + 1, (s + e) / 2 + 1, e, k);
}
int hap(int idx, int s, int e, int l, int r) {
	if (l > r)return 0;
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return tree[idx];
	return hap(idx * 2, s, (s + e) / 2, l, r)
		+ hap(idx * 2 + 1, (s + e) / 2 + 1, e, l, r);
}
int main() {
	int n, x, le, ri, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		arr[i] = { x,i };
	}
	sort(arr, arr + n, greater<pii>());
	for (int i = 0; i < n; i++) {
		le = hap(1, 0, n - 1, 0, arr[i].second - 1);
		ri = hap(1, 0, n - 1, arr[i].second + 1, n - 1);
		if (le > ri) swap(le, ri);
		if (le * 2 < ri) ans++;
		update(1, 0, n - 1, arr[i].second);
	}
	printf("%d", ans);

	return 0;
}
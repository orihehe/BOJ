/*
BOJ 17423 - 민원이 넘쳐흘러
https://www.acmicpc.net/problem/17423

구간의 max값을 lazy로 관리, 이분탐색을 이용하여 가능여부를 판단.
*/
#include <cstdio>
#include <algorithm>
#define INF 2000000010
#define MAX 2000000
using namespace std;

/* 🐣🐥 */
struct info {
	int sz, x, y;
} arr[100001];
int tree[4194304], n, lazy[4194304];
void update(int idx, int s, int e, int l, int r, int val) {
	if (e<l || s>r) return;
	if (l <= s && e <= r) {
		lazy[idx] = max(lazy[idx], val);
		tree[idx] = max(tree[idx], val);
		return;
	}
	update(idx * 2, s, (s + e) / 2, l, r, val);
	update(idx * 2 + 1, (s + e) / 2 + 1, e, l, r, val);
	tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
}
int find(int idx, int s, int e, int l, int r) {
	if (e<l || s>r) return -INF;
	if (l <= s && e <= r) return tree[idx];
	int ret = max(find(idx * 2, s, (s + e) / 2, l, r),
		find(idx * 2 + 1, (s + e) / 2 + 1, e, l, r));
	return max(ret, lazy[idx]);
}
bool suc(int mid) {
	int hap, s, e;
	bool ss, ee;
	fill(tree, tree + 4194304, -INF);
	fill(lazy, lazy + 4194304, -INF);
	for (int i = 0; i < n; i++) {
		if (i > 0 && arr[i].y == arr[i - 1].y && arr[i - 1].x + mid * arr[i - 1].sz > arr[i].x - mid * arr[i].sz) return false;
		hap = arr[i].x + arr[i].y;
		if (hap - mid * arr[i].sz < 2) s = 2, ss = false;
		else s = hap - mid * arr[i].sz, ss = true;
		if (hap + mid * arr[i].sz > MAX) e = MAX, ee = false;
		else e = hap + mid * arr[i].sz, ee = true;
		if (find(1, 2, MAX, s + ss, e - ee) > arr[i].y - arr[i].x - mid * arr[i].sz) return false;
		update(1, 2, MAX, s, e, arr[i].y - arr[i].x + mid * arr[i].sz);
	}
	return true;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i].sz);
	for (int i = 0; i<n; i++) scanf("%d %d", &arr[i].x, &arr[i].y);
	sort(arr, arr + n, [](info a, info b) {
		if (a.y == b.y) return a.x < b.x;
		return a.y < b.y;
	});
	int l = 1, r = MAX / 2, mid, ans = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		if (suc(mid)) {
			l = mid + 1;
			ans = mid;
		}
		else {
			r = mid - 1;
		}
	}
	printf("%d", ans);

	return 0;
}
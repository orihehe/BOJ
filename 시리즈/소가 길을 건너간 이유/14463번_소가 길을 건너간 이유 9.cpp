/*
BOJ 14463 - 소가 길을 건너간 이유 9
https://www.acmicpc.net/problem/14463

세그트리를 이용하여 현재 수의 범위 내에 한번씩만 등장하는 수의 개수를 세준다.
*/
#include <cstdio>
#define ll long long
using namespace std;

/* 🐣🐥 */
int arr[100001], tree[262145];
int ss[50001];
ll ans;
void update(int idx, int s, int e, int k, int val) {
	if (s > k || e < k) return;
	tree[idx] += val;
	if (s == e) return;
	update(idx * 2, s, (s + e) / 2, k, val);
	update(idx * 2 + 1, (s + e) / 2 + 1, e, k, val);
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}
int hap(int idx, int s, int e, int l, int r) {
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return tree[idx];
	return hap(idx * 2, s, (s + e) / 2, l, r)
		+ hap(idx * 2 + 1, (s + e) / 2 + 1, e, l, r);
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n; i++) {
		scanf("%d", &arr[i]);
		if (!ss[arr[i]])
			ss[arr[i]] = i;
	}
	for (int i = 1; i <= 2 * n; i++) {
		if (ss[arr[i]] == i) {
			update(1, 1, 2 * n, i, 1);
		}
		else {
			update(1, 1, 2 * n, ss[arr[i]], -1);
			ans += hap(1, 1, 2 * n, ss[arr[i]], i);
		}
	}
	printf("%lld", ans);

	return 0;
}
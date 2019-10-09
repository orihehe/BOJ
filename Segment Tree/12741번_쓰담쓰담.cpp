/*
BOJ 12741 - 쓰담쓰담
https://www.acmicpc.net/problem/12741
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int tree[262144], arr[100001];
void update(int idx, int s, int e, int k) {
	if (k < s || e < k) return;
	if (s == e) {
		tree[idx] = true;
		return;
	}
	int mid = (s + e) / 2;
	update(idx * 2, s, mid, k);
	update(idx * 2 + 1, mid + 1, e, k);
	tree[idx] = tree[idx * 2] & tree[idx * 2 + 1] & arr[mid] <= arr[mid + 1];
}
bool find(int idx, int s, int e, int l, int r) {
	if (e<l || s>r) return true;
	if (l <= s && e <= r) return tree[idx];
	int mid = (s + e) / 2;
	bool ret = find(idx * 2, s, mid, l, r)
		& find(idx * 2 + 1, mid + 1, e, l, r);
	if (l <= mid && mid + 1 <= r)
		ret &= arr[mid] <= arr[mid + 1];
	return ret;
}
int main() {
	int n, q, cm, a, b;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		update(1, 0, n - 1, i);
	}
	while (q--) {
		scanf("%d %d %d", &cm, &a, &b);
		a--, b--;
		if (cm == 1) {
			printf("%s\n", find(1, 0, n - 1, a, b) ? "CS204" : "HSS090");
		}
		else {
			swap(arr[a], arr[b]);
			update(1, 0, n - 1, a);
			update(1, 0, n - 1, b);
		}
	}

	return 0;
}
/*
BOJ 14459 - 소가 길을 건너간 이유 11
https://www.acmicpc.net/problem/14459
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
int A[100001], tree[262144];
pii B[100001];
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
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return tree[idx];
	return max(getMax(idx * 2, s, (s + e) / 2, l, r),
		getMax(idx * 2 + 1, (s + e) / 2 + 1, e, l, r));
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &A[i]);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &B[i].first);
		B[i].second = i;
	}
	sort(B + 1, B + n + 1);
	for (int i = 0; i < n; i++) {
		vector<int> tmp;
		for (int j = max(1, A[i] - 4); j <= min(n, A[i] + 4); j++)
			tmp.push_back(B[j].second);
		sort(tmp.begin(), tmp.end(), greater<int>());
		for (int v : tmp) {
			update(1, 1, n, v, getMax(1, 1, n, 0, v - 1) + 1);
		}
	}
	printf("%d", tree[1]);

	return 0;
}
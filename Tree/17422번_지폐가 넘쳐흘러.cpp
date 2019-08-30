/*
BOJ 17422 - 지폐가 넘쳐흘러
https://www.acmicpc.net/problem/17422
*/
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

/* 🐣🐥 */
ll tree[524289], mx[524289];
int arr[262144];
void update(int idx, int val) {
	arr[idx] = val;
	while (idx > 0) {
		tree[idx] = arr[idx] + max(tree[idx * 2], tree[idx * 2 + 1]);
		mx[idx] = max(mx[idx * 2], mx[idx * 2 + 1]);
		mx[idx] = max(mx[idx], arr[idx] + tree[idx * 2] + tree[idx * 2 + 1]);
		idx /= 2;
	}
}
int main() {
	int n, q, x, idx;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		update(i, x);
	}
	scanf("%d", &q);
	printf("%lld\n", mx[1]);
	while (q--) {
		scanf("%d %d", &idx, &x);
		update(idx, x);
		printf("%lld\n", mx[1]);
	}

	return 0;
}
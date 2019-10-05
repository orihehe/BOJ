/*
BOJ 13925 - 수열과 쿼리 13
https://www.acmicpc.net/problem/13925

ax+b꼴이 나온다. 곱과 합을 따로 관리해서 풀어준다.
*/
#include <cstdio>
#include <algorithm>
#define ll long long
#define mod 1000000007
using namespace std;

/* 🐣🐥 */
ll tree[524288], mul[524288], hap[524288];
int arr[100001];
void gift(int idx) {
	mul[idx * 2] = mul[idx] * mul[idx * 2] % mod;
	mul[idx * 2 + 1] = mul[idx] * mul[idx * 2 + 1] % mod;
	hap[idx * 2] = (hap[idx * 2] * mul[idx] + hap[idx]) % mod;
	hap[idx * 2 + 1] = (hap[idx * 2 + 1] * mul[idx] + hap[idx]) % mod;
	hap[idx] = 0; mul[idx] = 1;
}
void update(int idx, int s, int e, int l, int r, int m, int p) {
	if (s > r || e < l) return;
	if (l <= s && e <= r) {
		mul[idx] = mul[idx] * m%mod;
		hap[idx] = (hap[idx] * m + p) % mod;
		return;
	}
	gift(idx);
	int mid = (s + e) / 2;
	update(idx * 2, s, mid, l, r, m, p);
	update(idx * 2 + 1, mid + 1, e, l, r, m, p);
	ll le, ri;
	le = tree[idx * 2] * mul[idx * 2] + hap[idx * 2] * (mid - s + 1);
	ri = tree[idx * 2 + 1] * mul[idx * 2 + 1] + hap[idx * 2 + 1] * (e - mid);
	tree[idx] = (le + ri) % mod;
}
ll find(int idx, int s, int e, int l, int r) {
	if (s > r || e < l) return 0;
	int le = max(s, l), ri = min(e, r);
	if (l <= s && e <= r) {
		return (tree[idx] * mul[idx] + hap[idx] * (ri - le + 1)) % mod;
	}
	ll x = find(idx * 2, s, (s + e) / 2, l, r) +
		find(idx * 2 + 1, (s + e) / 2 + 1, e, l, r);
	return (x*mul[idx] + hap[idx] * (ri - le + 1)) % mod;
}
int main() {
	int n, cm, a, b, c, q;
	fill(mul, mul + 524288, 1);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		update(1, 1, n, i, i, 1, arr[i]);
	}
	scanf("%d", &q);
	while (q--) {
		scanf("%d %d %d", &cm, &a, &b);
		if (cm == 1) {
			scanf("%d", &c);
			update(1, 1, n, a, b, 1, c);
		}
		else if (cm == 2) {
			scanf("%d", &c);
			update(1, 1, n, a, b, c, 0);
		}
		else if (cm == 3) {
			scanf("%d", &c);
			update(1, 1, n, a, b, 0, c);
		}
		else {
			printf("%lld\n", find(1, 1, n, a, b));
		}
	}

	return 0;
}
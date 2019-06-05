/*
BOJ 17131 - 여우가 정보섬에 올라온 이유
https://www.acmicpc.net/problem/17131
*/
#include <cstdio>
#include <vector>
#define ll long long
#define mod 1000000007
#define MAX 400002
#define M 200001
using namespace std;

/* 🐣🐥 */
vector<int> vec[400002];
int tree[1048577];
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
	int n, a, b;
	ll ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		a += M, b += M;
		vec[b].push_back(a);
	}
	for (int i = 400001; i >= 0; i--) {
		for (int v : vec[i]) {
			ans = (ans + 1LL * hap(1, 0, MAX, 0, v - 1) * hap(1, 0, MAX, v + 1, MAX)) % mod;
		}
		for (int v : vec[i]) {
			update(1, 0, MAX, v);
		}
	}
	printf("%lld", ans);

	return 0;
}
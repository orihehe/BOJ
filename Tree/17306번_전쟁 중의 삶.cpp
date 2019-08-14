/*
BOJ 17306 - 전쟁 중의 삶
https://www.acmicpc.net/problem/17306
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;

/* 🐣🐥 */
ll arr[250001];
ll wprhq[51];
vector<ll> vec[51];
ll lca(ll a, ll b) {
	if (a > b) swap(a, b);
	int lm = upper_bound(wprhq, wprhq + 51, a) - wprhq;
	while (b >= wprhq[lm]) b /= 2;
	while (a != b) {
		a /= 2, b /= 2;
	}
	return a;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
	wprhq[0] = 1;
	for (int i = 1; i <= 50; i++) {
		wprhq[i] = wprhq[i - 1] * 2;
	}
	ll lc = lca(arr[0], arr[1]);
	for (int i = 2; i < n; i++) {
		lc = lca(lc, arr[i]);
	}
	for (int i = 0; i < n; i++) {
		int lm = upper_bound(wprhq, wprhq + 51, arr[i]) - wprhq - 1;
		while (arr[i] != lc) {
			vec[lm--].push_back(arr[i]);
			arr[i] /= 2;
		}
	}
	ll ans = 0;
	for (int i = 1; i <= 50; i++) {
		sort(vec[i].begin(), vec[i].end());
		vec[i].erase(unique(vec[i].begin(), vec[i].end()), vec[i].end());
		ans += vec[i].size();
	}
	printf("%lld", ans + 1);

	return 0;
}
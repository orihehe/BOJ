/*
BOJ 17305 - 사탕 배달
https://www.acmicpc.net/problem/17305
*/
#include <cstdio>
#include <algorithm>
#include <functional>
#define ll long long
using namespace std;

/* 🐣🐥 */
ll s[250000], c[250000];
int main() {
	int n, w, sp = 0, cp = 0, a, b;
	ll ans = 0;
	scanf("%d %d", &n, &w);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		if (a == 3) s[sp++] = b;
		else c[cp++] = b;
	}
	sort(s, s + sp, greater<ll>());
	sort(c, c + cp, greater<ll>());
	for (int i = 1; i < sp; i++) s[i] += s[i - 1];
	for (int i = 1; i < cp; i++) c[i] += c[i - 1];
	for (int i = 0; i < sp; i++) {
		if (3 * (i + 1) > w) break;
		int idx = (w - 3 * (i + 1)) / 5 - 1;
		ans = max(ans, s[i] + ((idx >= 0 && cp > 0) ? c[min(cp - 1, idx)] : 0));
	}
	if (cp > 0 && w >= 5) {
		ans = max(ans, c[min(w / 5 - 1, cp - 1)]);
	}
	printf("%lld", ans);

	return 0;
}
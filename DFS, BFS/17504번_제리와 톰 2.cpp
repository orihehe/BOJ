/*
BOJ 17504 - 제리와 톰 2
https://www.acmicpc.net/problem/17504
*/
#include <cstdio>
#include <algorithm>
#define ll long long
#define pll pair<ll,ll>
using namespace std;

/* 🐣🐥 */
int arr[16];
int n;
ll gcd(ll a, ll b) {
	if (a > b)swap(a, b);
	while (a) {
		ll tmp = a;
		a = b % a;
		b = tmp;
	}
	return b;
}
pll dfs(int cur) {
	if (cur == n - 1) return { 1,arr[cur] };
	pll ret = dfs(cur + 1);
	ll tmp = arr[cur] * ret.second + ret.first;
	ll s = gcd(tmp, ret.second);
	return { ret.second / s,tmp / s };
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	pll ans = dfs(0);
	printf("%lld %lld", ans.second - ans.first, ans.second);

	return 0;
}
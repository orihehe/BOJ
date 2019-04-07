/*
BOJ 16565 - N포커
https://www.acmicpc.net/problem/16565

나올 수 있는 포카드 개수를 이용하여 경우를 구해준다.
*/
#include <cstdio>
#define ll long long
#define mod 10007
using namespace std;

/* 🐣🐥 */
ll myPow(ll a, ll b) {
	ll ans = 1;
	while (b > 0) {
		if (b % 2 == 1) {
			ans = (ans*a) % mod;
		}
		a = (a*a) % mod;
		b /= 2;
	}
	return ans;
}
int main() {
	ll n, ans = 0, x, up, dw;
	bool bu = true;
	scanf("%lld", &n);
	for (ll i = 1; i <= n / 4; i++) { // set
		x = up = dw = 1;
		for (ll xx = 13, j = 0; j < i; j++) {
			x *= xx;
			xx--;
		}
		for (ll j = i; j >= 2; j--)
			x /= j;
		x %= mod;
		for (ll j = n - i * 4 + 1; j <= 52 - i * 4; j++) {
			up = (up*j) % mod;
		}
		for (ll j = 2; j <= 52 - i * 4 - (n - i * 4); j++) {
			dw = (dw*j) % mod;
		}
		up = up * myPow(dw, mod - 2) % mod;
		x = x * up%mod;
		if (bu) {
			bu = false;
			ans = (ans + x) % mod;
		}
		else {
			bu = true;
			ans = (ans - x + mod) % mod;
		}
	}
	printf("%lld", ans);

	return 0;
}
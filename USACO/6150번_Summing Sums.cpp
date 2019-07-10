/*
BOJ 6150 - Summing Sums
https://www.acmicpc.net/problem/6150

나의 등장, 다른것의 등장 횟수는 항상 1차이가 난다.
홀수, 짝수에 따라 내가 더 크고, 작은것이 다르니 나누어서 행렬곱
*/
#include <cstdio>
#include <cstring>
#include <vector>
#define ll long long
#define mod 98765431
using namespace std;

/* 🐣🐥 */
ll arr[50001], tmp[2][2], ret[2][2];
vector<ll> ans;
void met(ll a[][2], ll b[][2]) {
	ll rr[2][2] = { 0, };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				rr[i][j] += a[i][k] * b[k][j];
			}
			rr[i][j] %= mod;
		}
	}
	memcpy(a, rr, sizeof(rr));
}
void calc(int b) {
	ret[0][0] = 1, ret[1][1] = 1;
	while (b > 0) {
		if (b % 2) {
			met(ret, tmp);
		}
		b /= 2;
		met(tmp, tmp);
	}
}
int main() {
	int n, t;
	ll an = 0, a;
	scanf("%d %d", &n, &t);
	a = n - 1;
	for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);

	tmp[0][0] = a * a;
	tmp[1][1] = 1;
	if (t % 2) tmp[0][1] = a * a - a;
	else tmp[0][1] = -a * a + a;

	calc(t / 2);
	ll cur = (t % 2 == 0)*ret[0][0] + ret[0][1];
	cur %= mod;
	for (int i = 0; i < n; i++) {
		if (t % 2 == 0) {
			an = (an + (cur - 1 + mod) % mod*arr[i]) % mod;
		}
		else an = (an + (cur + 1)*arr[i]) % mod;
	}
	for (int i = 0; i < n; i++) {
		ans.push_back(an + ((t % 2 == 0) ? arr[i] : -arr[i]));
	}
	for (ll v : ans) printf("%lld\n", (v + mod) % mod);

	return 0;
}
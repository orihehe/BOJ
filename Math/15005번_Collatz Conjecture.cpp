/*
BOJ 15005 - Collatz Conjecture
https://www.acmicpc.net/problem/15005

내 소인수는 log10^18개 정도로 작다.
따라서 현재 값을 j로 잡고 1~j-1, 2~j-1 ... 의 gcd값들과 gcd를 하면 된다.
*/
#include <cstdio>
#include <algorithm>
#include <set>
#define ll long long
using namespace std;

/* 🐣🐥 */
ll tt[70];
set<ll> sss, ans;
ll gcd(ll a, ll b) {
	if (a < b) swap(b, a);
	while (b > 0) {
		ll tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}
int main() {
	int n, tp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &tt[0]);
		tp = 1;
		for (auto iter = sss.begin(); iter != sss.end(); iter++) {
			tt[tp++] = gcd(*iter, tt[0]);
		}
		sss.clear();
		for (int j = 0; j < tp; j++) {
			ans.insert(tt[j]);
			sss.insert(tt[j]);
		}
	}
	printf("%d", ans.size());

	return 0;
}
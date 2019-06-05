/*
BOJ 10775 (https://www.acmicpc.net/problem/10775)
*/
#include <cstdio>
#include <map>
#include <cmath>
#define ll long long
using namespace std;

map<ll, ll> mp;
ll n, p, q;
ll go(ll cur) {
	if (mp.find(cur) == mp.end()) {
		return mp[cur] = go(floor(cur / p)) + go(floor(cur / q));
	}
	else return mp[cur];
}
int main() {
	mp[0] = 1;
	scanf("%lld %lld %lld", &n, &p, &q);
	printf("%lld", go(n));

	return 0;
}
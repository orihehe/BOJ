/*
BOJ 14454 - Secret Cow Code
https://www.acmicpc.net/problem/14454
*/
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;

/* 🐣🐥 */
char st[31];
int len;
char solve(ll idx, ll cur) {
	if (cur == (ll)len) return st[idx];
	if (idx >= cur / 2)
		idx = (idx - 1) % (cur / 2);
	return solve(idx, cur / 2);
}
int main() {
	ll n, tmp;
	scanf("%s %lld", st, &n);
	len = strlen(st);
	tmp = len;
	while (n > tmp) tmp *= 2;
	printf("%c", solve(n - 1, tmp));

	return 0;
}
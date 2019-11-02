/*
BOJ 16584 - Binary String
https://www.acmicpc.net/problem/16584
*/
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;

/* 🐣🐥 */
char st[61];
ll calc(int len) {
	ll x = 1, tmp = 0;
	for (int i = len - 1; i >= 0; i--) {
		if (st[i] == '.') continue;
		if (st[i] == '1') tmp += x;
		x <<= 1;
	}
	return tmp;
}
int main() {
	ll n, tmp = 0, cnt = 0, x = 1;
	scanf("%lld %s", &n, st);
	int len = strlen(st);
	for (int i = len - 1; i >= 0; i--) {
		if (st[i] == '1') tmp += x;
		x <<= 1;
	}
	for (int i = 1; i < len; i++) {
		if (tmp <= n) break;
		if (st[i] == '1') {
			st[i] = '.';
			tmp = calc(len);
			cnt++;
		}
	}
	while (tmp > n) {
		cnt++;
		tmp >>= 1;
	}
	printf("%d", cnt);

	return 0;
}
/*
BOJ 13713 - 문자열과 쿼리
https://www.acmicpc.net/problem/13713

위치는 정해져있으니 이분탐색으로 길이를 정해서 같은 문자열인지 판별해준다.
*/
#include <cstdio>
#include <cstring>
#define ll long long
#define mod1 1000000009
#define mod2 1000000021
using namespace std;

/* 🐣🐥 */
char st[1000002];
ll jin[2][1000001], wprhq[2][1000001];
int main() {
	int n, m, l, r, mid, loc, ans;
	ll x=1, y=1;
	scanf("%s", st + 1);
	n = strlen(st + 1);
	for (int i = 0; i < n; i++) {
		wprhq[0][i] = x;
		wprhq[1][i] = y;
		x = x * 127 % mod1;
		y = y * 127 % mod2;
	}
	for (int i = 1; i <= n; i++) {
		jin[0][i] = (jin[0][i - 1] + st[i] * wprhq[0][n - i]) % mod1;
		jin[1][i] = (jin[1][i - 1] + st[i] * wprhq[1][n - i]) % mod2;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &loc);
		l = 1, r = 1000000;
		ans = 0;
		while (l <= r) {
			mid = (l + r) / 2;
			if (mid > loc) {
				r = mid - 1;
				continue;
			}
			ll tmp1 = (jin[0][n] - jin[0][n - mid] + mod1) % mod1 * wprhq[0][n - loc] % mod1;
			ll tmp2 = (jin[1][n] - jin[1][n - mid] + mod2) % mod2 * wprhq[1][n - loc] % mod2;
			ll ori1 = (jin[0][loc] - jin[0][loc - mid] + mod1) % mod1;
			ll ori2 = (jin[1][loc] - jin[1][loc - mid] + mod2) % mod2;
			if (tmp1*mod2 + tmp2 == ori1 * mod2 + ori2) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		printf("%d\n", ans);
	}

	return 0;
}
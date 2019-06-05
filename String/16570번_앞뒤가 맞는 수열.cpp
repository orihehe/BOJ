/*
BOJ 16570 - 앞뒤가 맞는 수열
https://www.acmicpc.net/problem/16570

앞에서부터 잘랐을 때 일치하는 가장 긴 길이를 유지/증가 시키며 봐준다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
#define mod1 1000000009
#define mod2 1000000021
using namespace std;

/* 🐣🐥 */
ll vec1[1000001], vec2[1000001];
ll wprhq[2][1000001], x = 1, y = 1;
int main() {
	int n, c, s, e, len = 0, cnt = 0;
	scanf("%d", &n);
	s = e = n;
	for (int i = 0; i < n; i++) {
		wprhq[0][i] = x;
		wprhq[1][i] = y;
		x = x * 256 % mod1;
		y = y * 256 % mod2;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c);
		vec1[i] = (vec1[i - 1] + c * wprhq[0][n-i] % mod1) % mod1;
		vec2[i] = (vec2[i - 1] + c * wprhq[1][n-i] % mod2) % mod2;
	}
	for (int i = 1; i < n; i++) { // 시작점
		ll tmp1 = (vec1[i] - vec1[i - len] + mod1) % mod1 * wprhq[0][i - len] % mod1;
		ll tmp2 = (vec2[i] - vec2[i - len] + mod2) % mod2 * wprhq[1][i - len] % mod2;
		ll t1 = (vec1[n] - vec1[n - len] + mod1) % mod1 * wprhq[0][n - len] % mod1;
		ll t2 = (vec2[n] - vec2[n - len] + mod2) % mod2 * wprhq[1][n - len] % mod2;
		if (tmp1 * tmp2 == t1 * t2) cnt++;
		while (i-len-1>=0) {
			len++;
			tmp1 = (vec1[i] - vec1[i - len] + mod1) % mod1 * wprhq[0][i - len] % mod1;
			tmp2 = (vec2[i] - vec2[i - len] + mod2) % mod2 * wprhq[1][i - len] % mod2;
			t1 = (vec1[n] - vec1[n - len] + mod1) % mod1 * wprhq[0][n - len] % mod1;
			t2 = (vec2[n] - vec2[n - len] + mod2) % mod2 * wprhq[1][n - len] % mod2;
			if (tmp1 * tmp2 == t1 * t2) cnt = 1;
			else {
				len--; break;
			}
		}
	}

	if (len == 0) printf("-1");
	else printf("%d %d", len, cnt);

	return 0;
}
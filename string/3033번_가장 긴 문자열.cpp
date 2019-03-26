/*
BOJ 3033 - 가장 긴 문자열
https://www.acmicpc.net/problem/3033

이분탐색으로 문자열의 길이를 정해두고 모든 그 길이의 부분문자열을 확인해준다.
*/
#include <cstdio>
#include <unordered_set>
#define ll long long
#define mod1 1000000009
#define mod2 1000000021
using namespace std;

/* 🐣🐥 */
unordered_set<ll> sss;
ll arr[200001], vec[200001], wprhq[2][200001];
char st[200001];
int main() {
	int n, ans = 0, l, r, mid;
	ll x = 1, y = 1;
	scanf("%d", &n);
	scanf("%s", st + 1);
	for (int i = 0; i < n; i++) {
		wprhq[0][i] = y;
		wprhq[1][i] = x;
		x = x * 127 % mod2;
		y = y * 127 % mod1;
	}
	for (int i = 1; i <= n; i++) {
		arr[i] = (arr[i - 1] + wprhq[0][n - i] * st[i] % mod1) % mod1;
	}
	for (int i = 1; i <= n; i++) {
		vec[i] = (vec[i - 1] + wprhq[1][n - i] * st[i] % mod2) % mod2;
	}
	l = 0, r = n;
	while (l <= r) {
		mid = (l + r) / 2;
		bool suc = false;
		sss.clear();
		for (int i = mid; i <= n; i++) {
			ll tmp = (vec[i] - vec[i - mid] + mod2) % mod2 * wprhq[1][i - mid] % mod2;
			ll tmp2 = (arr[i] - arr[i - mid] + mod1) % mod1 * wprhq[0][i - mid] % mod1;
			if (sss.count(tmp*tmp2) > 0) {
				suc = true;
				break;
			}
			sss.insert(tmp*tmp2);
		}
		if (suc) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	printf("%d", ans);

	return 0;
}
/*
BOJ 16908 - 가장 긴 공통 부분 문자열
https://www.acmicpc.net/problem/16908

해시값이 같고 이전 비트가 모두 켜져있는 원소를 map에서 찾아 현재 비트를 켜준다.
모든 비트가 켜졌다면 그 길이는 가능, 이분탐색으로 가장 긴 길이를 찾아준다.
*/
#include <cstdio>
#include <cstring>
#include <unordered_map>
#define ll long long
#define mod1 1000000009
#define mod2 1000000021
using namespace std;

/* 🐣🐥 */
unordered_map<ll, int> sss;
ll arr[10][100001], vec[10][100001], wprhq[2][100001];
int lee[10];
char st[100002];
int main() {
	int n, ans = 0, l, r, mid, len;
	ll x = 1, y = 1;
	scanf("%d", &n);
	for (int i = 0; i < 100001; i++) {
		wprhq[0][i] = y;
		wprhq[1][i] = x;
		x = x * 127 % mod2;
		y = y * 127 % mod1;
	}
	for (int k = 0; k < n; k++) {
		scanf("%s", st + 1);
		len = strlen(st + 1);
		lee[k] = len;
		for (int i = 1; i <= len; i++) {
			arr[k][i] = (arr[k][i - 1] + wprhq[0][100001 - i] * st[i] % mod1) % mod1;
		}
		for (int i = 1; i <= len; i++) {
			vec[k][i] = (vec[k][i - 1] + wprhq[1][100001 - i] * st[i] % mod2) % mod2;
		}
	}

	l = 1, r = 100000;
	while (l <= r) {
		mid = (l + r) / 2;
		bool suc = false;
		sss.clear();
		for (int i = mid; i <= lee[0]; i++) {
			ll tmp = (vec[0][i] - vec[0][i - mid] + mod2) % mod2 * wprhq[1][i - mid] % mod2;
			ll tmp2 = (arr[0][i] - arr[0][i - mid] + mod1) % mod1 * wprhq[0][i - mid] % mod1;
			sss[tmp*mod1 + tmp2] = 1;
		}
		for (int k = 1; k < n; k++) {
			int ttt = 1 << k;
			for (int i = mid; i <= lee[k]; i++) {
				ll tmp = (vec[k][i] - vec[k][i - mid] + mod2) % mod2 * wprhq[1][i - mid] % mod2;
				ll tmp2 = (arr[k][i] - arr[k][i - mid] + mod1) % mod1 * wprhq[0][i - mid] % mod1;

				auto xx = sss.find(tmp*mod1 + tmp2);
				if (xx != sss.end() && xx->second == ttt - 1) {
					xx->second |= ttt;
					if (k == n - 1) {
						suc = true;
						break;
					}
				}
			}
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
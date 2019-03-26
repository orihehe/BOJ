/*
BOJ 14525 - Bovine Genomics (Gold) 
https://www.acmicpc.net/problem/14525
*/
#include <cstdio>
#include <vector>
#include <unordered_set>
#define ll long long
#define mod1 1000000009
#define mod2 1000000021
using namespace std;

/* 🐣🐥 */
unordered_set<ll> sss;
ll arr[1001][502], vec[1001][502], wprhq[2][502];
char st[502];
vector<int> ans;
int main() {
	int n, m, ans, l, r, mid;
	ll x = 1, y = 1;
	for (int i = 0; i < 502; i++) {
		wprhq[0][i] = y;
		wprhq[1][i] = x;
		y = y * 127 % mod1;
		x = x * 127 % mod2;
	}
	scanf("%d %d", &n, &m);
	for (int i = 0; i < 2 * n; i++) {
		scanf("%s", st + 1);
		for (int j = 1; j <= m; j++) {
			arr[i][j] = (arr[i][j - 1] + wprhq[0][501 - j] * st[j] % mod1) % mod1;
			vec[i][j] = (vec[i][j - 1] + wprhq[1][501 - j] * st[j] % mod2) % mod2;
		}
	}
	l = 1, r = m;
	while (l <= r) {
		mid = (l + r) / 2;
		bool suc = false;
		for (int j = mid; j <= m; j++) {
			bool tt = false;
			sss.clear();
			for (int i = 0; i < n; i++) {
				ll tmp1 = (arr[i][j] - arr[i][j - mid] + mod1) % mod1*wprhq[0][j - mid] % mod1;
				ll tmp2 = (vec[i][j] - vec[i][j - mid] + mod2) % mod2*wprhq[1][j - mid] % mod2;
				sss.insert(tmp1*mod2 + tmp2);
			}
			for (int i = n; i < 2 * n; i++) {
				ll tmp1 = (arr[i][j] - arr[i][j - mid] + mod1) % mod1*wprhq[0][j - mid] % mod1;
				ll tmp2 = (vec[i][j] - vec[i][j - mid] + mod2) % mod2*wprhq[1][j - mid] % mod2;
				if (sss.count(tmp1*mod2 + tmp2) > 0) {
					tt = true;
					break;
				}
				if (tt) break;
			}
			if (!tt) suc = true;
		}
		if (suc) {
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	printf("%d", ans);

	return 0;
}
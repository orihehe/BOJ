/*
BOJ 7038 - Cow Patterns
https://www.acmicpc.net/problem/7038

원본을 해싱해두고, 찾을 패턴 배열을 같은 순위인 것만 보며 그 순위는 1 나머지는 0으로 두고 해싱
슬라이딩 윈도우로 현재 범위에 어떤 수가 몇 순위인지 알 수 있고,
그것으로 그 순위에 해당하는 해싱에 그 수를 곱한값을 모두 더한것이 원본의 해시값과 같으면 된다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define ll long long
#define mod1 1000000009
#define mod2 1000000021
using namespace std;

/* 🐣🐥 */
int arr[100002], w[25002], cnt[26];
ll wprhq[2][100002], ori[2][100002], tar[2][26];
vector<int> ans;
int main() {
	int n, k, s;
	ll x = 1, y = 1;
	scanf("%d %d %d", &n, &k, &s);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	for (int i = 1; i <= k; i++) scanf("%d", &w[i]);
	for (int i = 0; i < n; i++) {
		wprhq[0][i] = x;
		wprhq[1][i] = y;
		x = x * 256 % mod1;
		y = y * 256 % mod2;
	}
	for (int i = 1; i <= n; i++) {
		ori[0][i] = (ori[0][i - 1] + arr[i] * wprhq[0][n - i]) % mod1;
		ori[1][i] = (ori[1][i - 1] + arr[i] * wprhq[1][n - i]) % mod2;
	}
	for (int j = 1; j <= s; j++) {
		for (int i = 1; i <= k; i++) {
			tar[0][j] = (tar[0][j] + (w[i] == j) * wprhq[0][n - i]) % mod1;
			tar[1][j] = (tar[1][j] + (w[i] == j) * wprhq[1][n - i]) % mod2;
		}
	}
	for (int i = 1; i <= k; i++) cnt[arr[i]]++;
	int cur;
	for (int i = k; i <= n; i++) {
		cur = 1;
		ll hs[2] = { 0, };
		for (int j = 1; j <= s; j++) {
			if (cnt[j]) {
				hs[0] = (hs[0] + tar[0][cur] * j) % mod1;
				hs[1] = (hs[1] + tar[1][cur] * j) % mod2;
				cur++;
			}
		}
		ll tmp1 = (ori[0][i] - ori[0][i - k] + mod1)*wprhq[0][i - k] % mod1;
		ll tmp2 = (ori[1][i] - ori[1][i - k] + mod2)*wprhq[1][i - k] % mod2;
		if (hs[0] == tmp1 && hs[1] == tmp2) {
			ans.push_back(i - k + 1);
		}
		cnt[arr[i - k + 1]]--;
		cnt[arr[i + 1]]++;
	}
	printf("%d\n", ans.size());
	for (int v : ans) printf("%d\n", v);

	return 0;
}
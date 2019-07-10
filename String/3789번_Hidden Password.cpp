/*
BOJ 3789 - Hidden Password
https://www.acmicpc.net/problem/3789
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
char st[100001];
int tmp[100001], sa[100001], lcp[100001], pos[100001], cnt[100001], n;
void LCP() {
	for (int i = 0; i < n; i++) pos[i]--;
	for (int i = 0, k = 0; i < n; i++, k = max(k - 1, 0)) {
		if (!pos[i]) continue;
		for (int j = sa[pos[i] - 1]; st[j + k] == st[i + k]; k++);
		lcp[pos[i]] = k;
	}
}
void SA() {
	memset(pos, 0, sizeof(pos));
	memset(sa, 0, sizeof(sa));
	memset(tmp, 0, sizeof(tmp));
	for (int i = 0; i < n; i++) {
		sa[i] = i;
		pos[i] = st[i];
	}
	int p = 1, z = 0;
	while (true) {
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++) cnt[pos[min(n, i + p)]]++;
		for (int i = 1; i <= max(n, 128); i++) cnt[i] += cnt[i - 1];
		for (int i = n - 1; i >= 0; i--) tmp[--cnt[pos[min(n, i + p)]]] = i;

		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++) cnt[pos[i]]++;
		for (int i = 1; i <= max(n, 128); i++) cnt[i] += cnt[i - 1];
		for (int i = n - 1; i >= 0; i--) sa[--cnt[pos[tmp[i]]]] = tmp[i];

		if (z == n) break;

		z = 1, tmp[sa[0]] = 1;
		for (int i = 1; i < n; i++) {
			if (pos[sa[i]] != pos[sa[i - 1]] || pos[sa[i] + p] != pos[sa[i - 1] + p]) z++;
			tmp[sa[i]] = z;
		}
		memcpy(pos, tmp, sizeof(pos));
		p *= 2;
	}
	LCP();
}
int main() {
	int tt, ans;
	scanf("%d", &tt);
	while (tt--) {
		scanf("%d %s", &n, st);
		SA();
		ans = sa[0];
		for (int i = 1; i < n; i++) {
			int len = n - sa[i - 1];
			if (lcp[i] != len) break;
			if (pos[0] < pos[sa[i] + len]) break;
			ans = sa[i];
		}
		printf("%d\n", ans);
	}

	return 0;
}
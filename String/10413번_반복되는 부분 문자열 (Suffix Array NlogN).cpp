/*
BOJ 10413 - 반복되는 부분 문자열
https://www.acmicpc.net/problem/10413
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
char st[100001];
int n, pos[100001], lcp[100001], sa[100001], tmp[100001], cnt[100001];
void LCP() {
	for (int i = 0; i < n; i++) pos[i]--;
	for (int i = 0, k = 0; i < n; i++, k = max(k - 1, 0)) {
		if (!pos[i]) continue;
		for (int j = sa[pos[i] - 1]; st[i + k] == st[j + k]; k++);
		lcp[pos[i]] = k;
	}
}
void SA() {
	memset(pos, 0, sizeof(pos));
	memset(tmp, 0, sizeof(tmp));
	for (int i = 0; i < n; i++) {
		sa[i] = i;
		pos[i] = st[i];
	}
	int p = 1, z = 0;
	while (true) {
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++) cnt[pos[min(i + p, n)]]++;
		for (int i = 1; i <= max(n, 128); i++) cnt[i] += cnt[i - 1];
		for (int i = n - 1; i >= 0; i--) tmp[--cnt[pos[min(i + p, n)]]] = i;

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
		ans = 0;
		scanf("%s", st);
		n = strlen(st);
		SA();
		for (int i = 1; i < n; i++)
			ans += max(0, lcp[i] - lcp[i - 1]);
		printf("%d\n", ans);
	}

	return 0;
}
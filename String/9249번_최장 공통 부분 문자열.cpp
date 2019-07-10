/*
BOJ 9249 - 최장 공통 부분 문자열
https://www.acmicpc.net/problem/9249
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
char st[200002];
int n;
int sa[200002], pos[200002], tmp[200002], cnt[200002], ans, ii, o;
void LCP() {
	for (int i = 0; i < n; i++) pos[i]--;
	for (int i = 0, k = 0, j; i < n; i++, k = max(0, k - 1)) {
		if (!pos[i]) continue;
		for (j = sa[pos[i] - 1]; st[i + k] == st[j + k]; k++);
		if (((j < o && i > o) || (j > o && i < o)) && k > ans) {
			ans = k;
			ii = i;
		}
	}
}
void SA() {
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
	scanf("%s", st);
	o = strlen(st);
	st[o] = 'A';
	scanf("%s", st + o + 1);
	n = strlen(st);
	SA();
	printf("%d\n", ans);
	for (int i = 0; i < ans; i++) printf("%c", st[i + ii]);

	return 0;
}
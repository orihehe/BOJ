/*
BOJ 11479 - 서로 다른 부분 문자열의 개수 2
https://www.acmicpc.net/problem/11479

같은 문자열 개수를 세서 전체 경우에서 빼준 값을 출력
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

/* 🐣🐥 */
char st[1000001];
int n;
int sa[1000001], pos[1000001], tmp[1000001], cnt[1000001];
ll ans;
void LCP() {
	for (int i = 0; i < n; i++) pos[i]--;
	for (int i = 0, k = 0, j; i < n; i++, k = max(0, k - 1)) {
		if (!pos[i]) continue;
		for (j = sa[pos[i] - 1]; st[i + k] == st[j + k]; k++);
		ans += k;
	}
}
void SA() {
	n = strlen(st);
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
	SA();
	printf("%lld", 1LL * n*(n + 1) / 2 - ans);

	return 0;
}
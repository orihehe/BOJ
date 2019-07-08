/*
BOJ 9248 - Suffix Array
https://www.acmicpc.net/problem/9248
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char st[500002];
int pos[500002], sa[500002], lcp[500002], d, len;
bool cmp(int a, int b) {
	if (pos[a] != pos[b]) return pos[a] < pos[b];
	a += d, b += d;
	// 범위를 넘어가면 짧은 문자열이 앞으로
	return (a < len && b < len) ? pos[a]<pos[b] : a>b;
}
void LCP() {
	for (int i = 0, k = 0; i < len; i++, k = max(0, k - 1)) {
		if (pos[i] == 0) continue;
		// 정렬된 접미사배열의 이전 것과 비교
		for (int j = sa[pos[i] - 1]; st[j + k] == st[i + k]; k++);
		lcp[pos[i]] = k;
	}
}
void SA() {
	for (int i = 0; i < len; i++) {
		pos[i] = st[i];
		sa[i] = i;
	}
	for (d = 1;; d *= 2) {
		sort(sa, sa + len, cmp);
		int tmp[500002] = { 0, };
		for (int i = 0; i < len - 1; i++) {
			tmp[i + 1] = tmp[i] + cmp(sa[i], sa[i + 1]);
		}
		for (int i = 0; i < len; i++) {
			pos[sa[i]] = tmp[i];
		}
		if (tmp[len - 1] == len - 1) break;
	}

	for (int i = 0; i < len; i++) {
		pos[sa[i]] = i;
	}
	LCP();
}

int main() {
	scanf("%s", st);
	len = strlen(st);
	SA();
	for (int i = 0; i < len; i++) printf("%d ", sa[i] + 1);
	printf("\nx ");
	for (int i = 1; i < len; i++) {
		printf("%d ", lcp[i]);
	}

	return 0;
}
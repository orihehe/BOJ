/*
BOJ 4354 - 문자열 제곱
https://www.acmicpc.net/problem/4354
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

/* 🐣🐥 */
char st[1000001];
int fail[1000001];
int main() {
	while (scanf("%s", st)) {
		if (st[0] == '.') break;
		int n = strlen(st);
		memset(fail, 0, sizeof(fail));
		for (int i = 1, j = 0; i < n; i++) {
			while (j > 0 && st[j] != st[i]) j = fail[j - 1];
			if (st[j] == st[i]) fail[i] = ++j;
		}
		bool suc = (fail[n - 1] != 0);
		int ans = n - fail[n - 1], cnt = 1;
		if (n%ans) suc = false;
		for (int i = ans * 2 - 1; i < n; i += ans, cnt++) {
			if (ans*cnt != fail[i]) suc = false;
		}
		printf("%d\n", suc ? n / ans : 1);
	}

	return 0;
}
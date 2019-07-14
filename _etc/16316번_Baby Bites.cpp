/*
BOJ 16316 - Baby Bites
https://www.acmicpc.net/problem/16316
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
char st[6];
int toi() {
	int tmp = 0, len = strlen(st);
	for (int i = 0; i < len; i++) {
		tmp *= 10;
		tmp += st[i] - '0';
	}
	return tmp;
}
int main() {
	int n, cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", st);
		cnt++;
		if (st[0] == 'm') continue;
		else if (toi() != cnt) return !printf("something is fishy");
	}
	printf("makes sense");

	return 0;
}
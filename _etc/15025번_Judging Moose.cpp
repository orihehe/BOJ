/*
BOJ 15025 - Judging Moose
https://www.acmicpc.net/problem/15025
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int main() {
	int l, r;
	scanf("%d %d", &l, &r);
	if (l == 0 && r == 0)
		printf("Not a moose");
	else if (l != r)
		printf("Odd %d", max(l, r) * 2);
	else printf("Even %d", l + r);

	return 0;
}
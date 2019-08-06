/*
BOJ 13473 - Anniversary Cake
https://www.acmicpc.net/problem/13473
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int main() {
	int w, h, x1, y1, x2, y2;
	scanf("%d %d %d %d %d %d", &w, &h, &x1, &y1, &x2, &y2);
	if (x1 != x2) printf("%d %d %d %d", x1, 0, x2, h);
	else printf("%d %d %d %d", 0, y1, w, y2);

	return 0;
}
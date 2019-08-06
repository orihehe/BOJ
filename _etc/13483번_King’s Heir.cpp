/*
BOJ 13483 - King’s Heir
https://www.acmicpc.net/problem/13483
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int day(int d, int m, int y) {
	return  372 * y + m * 31 + d;
}
int main() {
	int d, m, y, n, ans = -1, gap = -1, dd, mm, yy, ori;
	scanf("%d %d %d %d", &d, &m, &y, &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &dd, &mm, &yy);
		if (y - yy > 18) {
			if (gap < day(dd, mm, yy)) {
				gap = day(dd, mm, yy);
				ans = i;
			}
		}
		else if (y - yy == 18) {
			if (m - mm > 0) {
				if (gap < day(dd, mm, yy)) {
					gap = day(dd, mm, yy);
					ans = i;
				}
			}
			else if (m == mm && d - dd >= 0) {
				if (gap < day(dd, mm, yy)) {
					gap = day(dd, mm, yy);
					ans = i;
				}
			}
		}
	}
	printf("%d", ans);

	return 0;
}
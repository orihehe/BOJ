/*
BOJ 11758 - CCW
https://www.acmicpc.net/problem/11758

벡터의 외적
*/
#include <cstdio>

/* 🐣🐥 */
int vt(int x1, int y1, int x2, int y2) {
	return x1 * y2 - x2 * y1;
}
int main() {
	int x1, y1, x2, y2, x3, y3;
	scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
	int tmp = vt(x2 - x1, y2 - y1, x3 - x1, y3 - y1);
	if (tmp == 0) printf("0");
	else printf("%d", tmp < 0 ? -1 : 1);

	return 0;
}
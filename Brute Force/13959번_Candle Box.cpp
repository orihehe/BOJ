/*
BOJ 13959 - Candle Box
https://www.acmicpc.net/problem/13959
*/
#include <cstdio>
#include <cstring>
using namespace std;

/* 🐣🐥 */
int main() {
	int d, x, y;
	int xx = 0;
	scanf("%d %d %d", &d, &x, &y);
	for (int i = 4;; i++) {
		xx += i;
		int sum = xx;
		for (int j = 3; j <= i - d; j++) sum += j;
		if (sum == x + y) {
			return !printf("%d", x - xx);
		}
	}
	return 0;
}
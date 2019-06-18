/*
BOJ 16288 - Passport Control
https://www.acmicpc.net/problem/16288
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int q[101];
int main() {
	int n, k, x, j;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		for (j = 0; j < k; j++) {
			if (q[j] < x) {
				q[j] = x;
				break;
			}
		}
		if (j == k) return !printf("NO");
	}
	printf("YES");

	return 0;
}
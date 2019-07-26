/*
BOJ 16070 - It’s Time for a Montage
https://www.acmicpc.net/problem/16070
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int a[1001], b[1001];
int main() {
	int n, x = 1001, y = 0, z = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);
	for (int i = 0; i < n - 1; i++) {
		x = min(x, max(y, b[i] - a[i] + 1));
		y = max(y, b[i] - a[i]);
	}
	x = min(x, max(y, b[n - 1] - a[n - 1]));
	printf("%d", x);

	return 0;
}
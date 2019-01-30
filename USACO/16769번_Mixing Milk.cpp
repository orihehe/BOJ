/*
BOJ 16769 (https://www.acmicpc.net/problem/16769)
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int a[3], am[3];
	scanf("%d %d", &a[0], &am[0]);
	scanf("%d %d", &a[1], &am[1]);
	scanf("%d %d", &a[2], &am[2]);
	for (int i = 0; i < 100; i++) {
		if (am[(i + 1) % 3] + am[i % 3] <= a[(i + 1) % 3]) {
			am[(i + 1) % 3] += am[i % 3];
			am[i % 3] = 0;
		}
		else {
			int tmp = min(a[(i + 1) % 3] - am[(i + 1) % 3], a[i % 3]);
			am[i % 3] -= tmp;
			am[(i + 1) % 3] += tmp;
		}
	}
	for (int i = 0; i < 3; i++) {
		printf("%d\n", am[i]);
	}

	return 0;
}
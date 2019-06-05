/*
BOJ 2231 ºÐÇØÇÕ (https://www.acmicpc.net/problem/2231)

*/
#include <cstdio>

int sbin(int x) {
	int sum = 0;
	while (x > 0) {
		sum += x % 10;
		x /= 10;
	}
	return sum;
}
int main() {
	int n;
	bool suc = false;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		if ((i + sbin(i)) == n) {
			printf("%d", i);
			suc = true;
			break;
		}
	}
	if (!suc) printf("0");

	return 0;
}
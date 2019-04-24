/*
BOJ 16563 - 어려운 소인수분해
https://www.acmicpc.net/problem/16563

첫 소숫값을 배열에 저장해두고, 나눠주며 소인수분해
*/
#include <cstdio>
#define MAX 5000001
using namespace std;

/* 🐣🐥 */
int sosu[MAX];
int main() {
	for (int i = 2; i < MAX; i++) {
		if (!sosu[i]) {
			for (int j = 1; j*i < MAX; j++) {
				if (!sosu[j*i]) sosu[j*i] = i;
			}
		}
	}
	int n, x;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &x);
		while (sosu[x]) {
			printf("%d ", sosu[x]);
			x /= sosu[x];
		}
		printf("\n");
	}

	return 0;
}
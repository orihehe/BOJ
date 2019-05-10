/*
BOJ 17173 - 배수들의 합
https://www.acmicpc.net/problem/17173
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
bool use[1001];
int main() {
	int n, m, k;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &k);
		for (int j = 1; j*k <= n; j++) {
			use[j*k] = true;
		}
	}
	int sum = 0;
	for (int i = 1; i <= 1000; i++) if (use[i]) sum += i;
	printf("%d", sum);

	return 0;
}
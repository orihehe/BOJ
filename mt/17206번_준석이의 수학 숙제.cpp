/*
BOJ 17206 - 준석이의 수학 숙제
https://www.acmicpc.net/problem/17206
*/
#include <cstdio>
#define MAX 80001
using namespace std;

/* 🐣🐥 */
bool num[MAX];
long long dp[MAX];
int main() {
	for (int i = 1; 3 * i < MAX; i++) num[3 * i] = true;
	for (int i = 1; 7 * i < MAX; i++) num[7 * i] = true;
	for (int i = 1; i < MAX; i++) dp[i] = dp[i - 1] + (num[i] ? i : 0);
	int t, x;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &x);
		printf("%lld\n", dp[x]);
	}

	return 0;
}
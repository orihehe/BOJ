/*
BOJ 17263 - Sort 마스터 배지훈
https://www.acmicpc.net/problem/17263
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int main() {
	int n, ans = 0, x;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &x);
		ans = ans > x ? ans : x;
	}
	printf("%d", ans);

	return 0;
}
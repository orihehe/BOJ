/*
BOJ 17496 - 스타후르츠
https://www.acmicpc.net/problem/17496
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int main() {
	int n, t, c, p;
	scanf("%d %d %d %d", &n, &t, &c, &p);
	printf("%d", (n - 1) / t * p*c);

	return 0;
}
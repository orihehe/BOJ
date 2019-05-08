/*
BOJ 15979 - 스승님 찾기
https://www.acmicpc.net/problem/15979

0,0 -> 0
최솟값은 2까지 나올 수 있다. n,m이라면 0,0 -> n-1,1 -> n,m
1인 경우는 n과 m의 gcd가 1일 때
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

/* 🐣🐥 */
int gcd(int x, int y) {
	int tmp;
	if (y > x) swap(x, y);
	while (y > 0) {
		tmp = x;
		x = y;
		y = tmp % y;
	}
	return x;
}
int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	m = abs(m), n = abs(n);
	int gg = gcd(m, n);
	if (m == 0 && n == 0) printf("0");
	else if (gg == 1) printf("1");
	else printf("2");

	return 0;
}
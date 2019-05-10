/*
BOJ 17177 - 내접사각형 만들기
https://www.acmicpc.net/problem/17177

답은 정수로만 있으니 a미만의 정수들 중 조건을 만족하는 것 출력
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int main() {
	int a, b, c, tmp;
	scanf("%d %d %d", &a, &b, &c);
	for (int x = 1; x < a; x++) {
		tmp = a * x + b * c;
		if (tmp*tmp == (a*a - b * b)*(a*a - c * c)) return !printf("%d", x);
	}
	printf("-1");

	return 0;
}
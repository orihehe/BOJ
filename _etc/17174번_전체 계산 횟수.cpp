/*
BOJ 17174 - 전체 계산 횟수
https://www.acmicpc.net/problem/17174
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int main() {
	int n, m;
	long long sum = 0;
	scanf("%d %d", &n, &m);
	while (n > 0) {
		sum += n;
		n /= m;
	}
	printf("%lld", sum);

	return 0;
}
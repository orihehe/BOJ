/*
BOJ 16723 (https://www.acmicpc.net/problem/16723)
큰 수부터 봐준다.
그 수로 나눠지는 개수 * 수 를 더하고, 개수를 세줘서 다음 수와 겹치는 걸 빼준다
*/
#include <cstdio>
#include <cmath>
#define ll long long
using namespace std;

int main() {
	int n, x = pow(2, 30), cnt = 0;
	ll sum = 0;
	scanf("%d", &n);
	n *= 2;
	while (x >= 2) {
		sum += (n / x - cnt)*x;
		cnt += n / x - cnt;
		x /= 2;
	}
	printf("%lld", sum);

	return 0;
}
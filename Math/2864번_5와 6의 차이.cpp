/*
BOJ 2864 5와 6의 차이 (https://www.acmicpc.net/problem/2864)
.
*/
#include <cstdio>
using namespace std;

int calc(int n, bool b) {
	int x = 1, sum=0;
	while (n>0) {
		if (n % 10 == 5 || n % 10 == 6) {
			if (b) {
				sum += x * 6;
			}
			else sum += x * 5;
		}
		else {
			sum += x * (n % 10);
		}
		x *= 10; n /= 10;
	}
	return sum;
}

int main() {
	int a, b, minS=0, maxS=0;
	scanf("%d %d", &a, &b);
	maxS += calc(a, true) + calc(b, true);
	minS += calc(a, false) + calc(b, false);
	printf("%d %d", minS, maxS);

	return 0;
}
/*
น้มุ 3486 Adding Reversed Numbers (https://www.acmicpc.net/problem/3486)
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int len(int num) {
	int tmp = 0;
	while (num > 0) {
		num /= 10;
		tmp++;
	}
	return tmp;
}
int reverse(int num) {
	int l = len(num);
	int tmp = 0, d = 1;
	while (l > 1) {
		d *= 10;
		l--;
	}
	while (d > 0) {
		tmp += num % 10 * d;
		d /= 10;
		num /= 10;
	}
	return tmp;
}
int main() {
	int t, a, b, ra, rb;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &a, &b);
		ra = reverse(a);
		rb = reverse(b);
		printf("%d\n", reverse(ra + rb));
	}

	return 0;
}
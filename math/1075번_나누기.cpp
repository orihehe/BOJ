// 백준 1075 나누기 (https://www.acmicpc.net/problem/1075)
#include <cstdio>
using namespace std;

int main() {
	int n, f, x, t;
	scanf("%d %d", &n, &f);
	x = n / 100 * 100;
	if(x%f!=0) x += f - (x % f);
	t = x % 10; x /= 10;
	printf("%d%d", x % 10, t);

	return 0;
}
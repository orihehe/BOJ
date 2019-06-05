/*
BOJ 16162 (https://www.acmicpc.net/problem/16162)

순서대로만 고음을 쌓을 수 있다.
따라서 앞에 나온 필요한 상태는 뒤에서 볼 필요가 없다.
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int main() {
	int n, a, k, x, l, cnt = 0;
	scanf("%d %d %d", &n, &a, &k);
	l = a - k;
	for (int i = 0; i<n; i++) {
		scanf("%d", &x);
		if (x - l == k) {
			l += k; cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}
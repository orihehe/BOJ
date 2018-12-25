/*
백준 4796 (https://www.acmicpc.net/problem/4796)
P일마다 L일을 다 사용하면 된다.
*/
#include <cstdio>
using namespace std;

int main() {
	int l, p, v, ca=1;
	scanf("%d %d %d", &l, &p, &v);
	while (l != 0 || p != 0 || v != 0) {
		printf("Case %d: %d\n", ca++, v / p * l + (v%p < l ? v % p : l));
		scanf("%d %d %d", &l, &p, &v);
	}

	return 0;
}
/*
���� 4796 (https://www.acmicpc.net/problem/4796)
P�ϸ��� L���� �� ����ϸ� �ȴ�.
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
/*
BOJ 14614 (https://www.acmicpc.net/problem/14614)

xor������ ¦���� �ϸ� ���� ���� ���ƿ´�.
���� �� ���ڰ� Ȧ���� ���� xor������ ��, ¦���� ���� a�� ���� ����Ѵ�.
*/
#include <cstdio>
#include <cstring>
char st[102];
int main() {
	int a, b, l;
	scanf("%d %d %s", &a, &b, st);
	l = strlen(st);
	if (st[l-1] % 2)
		printf("%d", a^b);
	else printf("%d", a);

	return 0;
}
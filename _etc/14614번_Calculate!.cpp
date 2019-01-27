/*
BOJ 14614 (https://www.acmicpc.net/problem/14614)

xor연산을 짝수번 하면 원래 수로 돌아온다.
따라서 끝 숫자가 홀수일 때는 xor연산의 값, 짝수일 때는 a의 값을 출력한다.
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
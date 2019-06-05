/*
BOJ 16194 (https://www.acmicpc.net/problem/16194)
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int d[1001], p[1001];
int main()
{
	int num;
	scanf("%d", &num);
	fill(p, p + num + 1, 10000001);
	p[0] = 0;
	for (int i = 1; i <= num; i++)
		scanf("%d", &d[i]);
	p[1] = d[1];
	p[2] = min(d[2], d[1] + p[1]);
	for (int i = 3; i <= num; i++)
		for (int j = 1; j <= i; j++)
			p[i] = min(p[i], d[j] + p[i - j]);
	printf("%d\n", p[num]);

	return 0;
}
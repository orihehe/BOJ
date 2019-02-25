/*
BOJ 11025 (https://www.acmicpc.net/problem/11025)

소풍(1242) 문제에서 원하는 사람의 위치 변화를 추적했다.
이 문제는 마지막 남은 사람을 원하므로 마지막 1명의 위치 1부터 거꾸로 구해준다.
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int main() {
	int n, m, loc;
	scanf("%d %d", &n, &m);
	loc = 1; // 마지막 위치
	for (int i = 2; i <= n; i++) {
		loc += m % i;
		if (loc > i) loc -= i;
	}
	printf("%d", loc);

	return 0;
}
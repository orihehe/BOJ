/*
BOJ 14456 (https://www.acmicpc.net/problem/14456)
1 2를 예로 들면 1이 2를 이기면 2는 3을 이겨야하고 3은 1을 이겨야 한다.
한 경우가 정해지면 다른것들이 자동으로 정해지므로 일단 1>2>3>1 으로 a의 이긴횟수, b의 이긴횟수를 셋다.
a가 더 조금 이겼다면 반대의 경우를 이긴것으로 치면 b의 이긴 횟수가 a의 이긴횟수가 된다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int xx(int x, int y) {
	if (x == y) return 0;
	if (x == 1) {
		if (y == 2) return 1;
		else return 2;
	}
	else if (x == 2) {
		if (y == 3) return 1;
		else return 2;
	}
	else {
		if (y == 1) return 1;
		else return 2;
	}
}
int main() {
	int n, a, b, cntA = 0, cntB = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		int res = xx(a, b);
		if (res == 2) cntB++;
		else if (res == 1) cntA++;
	}
	printf("%d", max(cntA, cntB));

	return 0;
}
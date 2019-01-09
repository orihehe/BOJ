/*
BOJ 14456 (https://www.acmicpc.net/problem/14456)
1 2�� ���� ��� 1�� 2�� �̱�� 2�� 3�� �̰ܾ��ϰ� 3�� 1�� �̰ܾ� �Ѵ�.
�� ��찡 �������� �ٸ��͵��� �ڵ����� �������Ƿ� �ϴ� 1>2>3>1 ���� a�� �̱�Ƚ��, b�� �̱�Ƚ���� �´�.
a�� �� ���� �̰�ٸ� �ݴ��� ��츦 �̱������ ġ�� b�� �̱� Ƚ���� a�� �̱�Ƚ���� �ȴ�.
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
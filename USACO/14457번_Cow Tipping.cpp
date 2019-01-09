/*
BOJ 14457 (https://www.acmicpc.net/problem/14457)
�� ���� ���� ������ ���簢�� ������ ����ϴµ�, Ƚ���� �ּҷ� �Ͽ� ��� ���¸� 0���� ������ �Ѵ�.
�Ųٷ� ��������� 0,0 ���� �հ����� 1�� �ִ��� Ž���Ͽ� ����Ͽ���.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char b[11][11];
void cha(int r, int c) { // 0�� 1�� 1�� 0���� 0,0 r,c���� ���
	for (int i = 0; i <= r; i++) {
		for (int j = 0; j <= c; j++) {
			if (b[i][j] == '0') b[i][j] = '1';
			else b[i][j] = '0';
		}
	}
}
int main() {
	int n, cur, cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", b[i]);
	}
	cur = n - 1;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i; j >= 0; j--) {
			if (b[i][j] == '1') {
				cha(i, j);
				cnt++;
			}
		}
		for (int j = i - 1; j >= 0; j--) {
			if (b[j][i] == '1') {
				cha(j, i);
				cnt++;
			}
		}
	}
	printf("%d", cnt);

	return 0;
}
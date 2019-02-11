/*
BOJ 16719 (https://www.acmicpc.net/problem/16719)

���� ���� ���� ã��, ã�� �ܾ� ���
������ ����̹Ƿ� ã�� �ε��� ���� ��, �� ������ ���ش�.
*/
#include <cstdio>
#include <cstring>
using namespace std;

char st[101];
bool view[101];
int len;
void go(int l, int r) {
	if (l >= r) return;
	int mV = 27, midx;
	for (int i = l; i < r; i++) {
		if (mV > st[i] - 'A') {
			mV = st[i] - 'A';
			midx = i;
		}
	}
	view[midx] = true;
	for (int i = 0; i < len; i++) {
		if (view[i])
			printf("%c", st[i]);
	}printf("\n");
	go(midx + 1, r);
	go(l, midx);
}
int main() {
	scanf("%s", st);
	len = strlen(st);
	go(0, len);

	return 0;
}
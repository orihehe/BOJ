/*
BOJ 14532 (https://www.acmicpc.net/problem/14532)
�� ó�� ��ĥ���� ���ɼ��� �ִ� ���� ������ ���ϴ� �����̴�.
���� �Է¹��� �� �� ���� ���� ��, �Ʒ�, ����, �������� �����ش�.
�� ���� ��-�Ʒ� x ��-������ ������ ������ ���簢������ ĥ�����ٰ� �� �� �ִ�.
�� ���� ������ �ٸ� ���� �ִٸ� �� ���簢�� �������� ĥ�������̹Ƿ� �ĺ����� �����Ѵ�.
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool use[10], no[10];
int n, cnt;
char b[11][11];
int loc[11][4]; // �� �Ʒ� �� ����
void isRec(int cur) {
	int i, j;
	for (i = loc[cur][0]; i <= loc[cur][1]; i++) {
		for (j = loc[cur][2]; j <= loc[cur][3]; j++) {
			if (b[i][j] != cur + '0') {
				no[b[i][j] - '0'] = false;
			}
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", b[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int cur = b[i][j] - '0';
			if (!use[cur]) {
				loc[cur][0] = loc[cur][1] = i;
				loc[cur][2] = loc[cur][3] = j;
				use[cur] = true; no[cur] = true;
			}
			else {
				loc[cur][0] = min(loc[cur][0], i);
				loc[cur][1] = max(loc[cur][1], i);
				loc[cur][2] = min(loc[cur][2], j);
				loc[cur][3] = max(loc[cur][3], j);
			}
		}
	}
	for (int i = 1; i < 10; i++) {
		if (use[i]) isRec(i);
	}
	for (int i = 1; i < 10; i++) {
		if (no[i]) cnt++;
	}
	printf("%d", cnt);

	return 0;
}
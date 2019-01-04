/*
BOJ 16116 (https://www.acmicpc.net/problem/16116)
ù ��° ���� ������ ������ ���� ���� ������ �����ϰ� ���� ���� �ִ� ������ ���鿡 �� ���̿��� ������.
�����鼭 ���� ���� üũ�ϴµ� ������ ���� ���� �ϳ��� �ƴϰų�, ������� �ִ� ���� 4���� �ƴ϶�� NO
������ ���� ���� �Ʒ������� ��� �� ���� �ִ� ���� ���鿡 �Ʒ������ ������ �Ѵ�.
���� ���鿡 ���� ������ �̾������� üũ�ϰ�, 
�� �� ���� ���� �� == �Ʒ��� ���� �� && ���� ���� �� == �Ʒ��� ���� �� �� ���� �����ؾ� �Ѵ�.

�ٸ���� �ڵ带 ���� ��� ���� ���� 3���̺��̴� 3���� ��쿡 (����)��==��, (����)��==�� �� ���� ���� �ϳ���� YES�� ���� �̿���
�ڵ带 �����ϰ� §�� �ô�.. ��
*/
#include <cstdio>
#include <algorithm>
using namespace std;

bool color[6];
int ap[26], cube[8][3], up, down = -1, sq[5], cnt;
void cl(int r) {
	int tmp = cube[r][2];
	cube[r][2] = cube[r][1];
	cube[r][1] = cube[r][0];
	cube[r][0] = tmp;
}
int main() {
	char x;
	ap[1] = 0, ap[6] = 1, ap[14] = 2;
	ap[17] = 3, ap[22] = 4, ap[24] = 5;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%c", &x);
			cube[i][j] = ap[x - 'A'];
			getchar();
		}
	}

	up = cube[0][0];
	for (int i = 0; i < 8; i++) {
		if (cube[i][0] == up || cube[i][1] == up || cube[i][2] == up) {
			for (int j = 0; j < 3; j++) {
				color[cube[i][j]] = true;
			}
			while (cube[i][0] != up) {
				cl(i);
			}
			cnt++;
		}
	}
	if (cnt != 4) {
		printf("NO"); return 0;
	}
	cnt = 0;
	for (int i = 0; i < 6; i++) {
		if (!color[i]) {
			down = i; cnt++;
		}
	}
	if (cnt == 0 || cnt >= 2) {
		printf("NO"); return 0;
	}
	for (int i = 0; i < 8; i++) {
		if (cube[i][0] != up) {
			if (cube[i][0] == down || cube[i][1] == down || cube[i][2] == down) {
				while (cube[i][0] != down) cl(i);
			}
			else {
				printf("NO"); return 0;
			}
		}
	}
	sq[0] = cube[0][1], sq[1] = cube[0][2];
	int stop = 1;
	for (int i = 0; i < 3; i++) {
		int j;
		for (j = 1; j < 8; j++) {
			if (cube[j][0] == up && cube[j][1] == sq[stop]) {
				sq[++stop] = cube[j][2];
				break;
			}
		}
		if (j == 8) {
			printf("NO"); return 0;
		}
	}
	for (int i = 1; i < 8; i++) {
		int j;
		if (cube[i][0] == down) {
			for (j = 0; j < 8; j++) {
				if (cube[j][0] == up && cube[i][1] == cube[j][2]
					&& cube[i][2] == cube[j][1]) {
					break;
				}
			}
			if (j == 8) {
				printf("NO"); return 0;
			}
		}
	}
	printf("YES");

	return 0;
}
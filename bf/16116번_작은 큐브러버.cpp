/*
BOJ 16116 (https://www.acmicpc.net/problem/16116)
첫 번째 블럭의 윗면을 합쳤을 때의 윗면 색으로 고정하고 윗면 색이 있는 블럭들을 윗면에 그 색이오게 돌린다.
돌리면서 사용된 색을 체크하는데 사용되지 않은 색이 하나가 아니거나, 윗면색이 있는 블럭이 4개가 아니라면 NO
사용되지 않은 색을 아랫면으로 잡고 그 색이 있는 블럭들 윗면에 아랫면색이 오도록 한다.
윗면 블럭들에 대해 옆면이 이어지는지 체크하고, 
그 후 윗면 블럭의 왼 == 아랫면 블럭의 오 && 윗면 블럭의 오 == 아랫면 블럭의 왼 인 블럭이 존재해야 한다.

다른사람 코드를 보니 모든 블럭에 대해 3면이보이는 3가지 경우에 (현재)왼==오, (현재)오==왼 인 블럭이 각각 하나라면 YES인 것을 이용해
코드를 간결하게 짠걸 봤다.. 흑
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
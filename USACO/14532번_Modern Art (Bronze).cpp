/*
BOJ 14532 (https://www.acmicpc.net/problem/14532)
맨 처음 색칠했을 가능성이 있는 수의 개수를 구하는 문제이다.
수를 입력받을 때 그 수의 가장 위, 아래, 왼쪽, 오른쪽을 구해준다.
그 수는 위-아래 x 왼-오른을 변으로 가지는 직사각형으로 칠해졌다고 볼 수 있다.
그 범위 내에서 다른 수가 있다면 그 직사각형 다음으로 칠해진것이므로 후보에서 제외한다.
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool use[10], no[10];
int n, cnt;
char b[11][11];
int loc[11][4]; // 위 아래 왼 오른
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
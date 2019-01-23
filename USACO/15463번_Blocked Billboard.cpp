/*
BOJ 15463 (https://www.acmicpc.net/problem/15463)

a와 b 각각 트럭과 겹치는 넓이를 뺀 값을 출력해준다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int ax1, ay1, ax2, ay2, bx1, by1, bx2, by2, as, bs;
	int tx1, ty1, tx2, ty2;
	scanf("%d %d %d %d", &ax1, &ay1, &ax2, &ay2);
	scanf("%d %d %d %d", &bx1, &by1, &bx2, &by2);
	scanf("%d %d %d %d", &tx1, &ty1, &tx2, &ty2);

	as = (ax2 - ax1)*(ay2 - ay1); 
	bs = (bx2 - bx1)*(by2 - by1);

	int atx1 = max(tx1, ax1);
	int aty1 = max(ty1, ay1);
	int atx2 = min(tx2, ax2);
	int aty2 = min(ty2, ay2);
	int btx1 = max(tx1, bx1);
	int bty1 = max(ty1, by1);
	int btx2 = min(tx2, bx2);
	int bty2 = min(ty2, by2);
	int ma, mb;
	if (atx1 > atx2 || aty1 > aty2) {
		ma = 0;
	}
	else {
		ma = (atx2 - atx1)*(aty2 - aty1);
	}
	if (btx1 > btx2 || bty1 > bty2) {
		mb = 0;
	}
	else {
		mb = (btx2 - btx1)*(bty2 - bty1);
	}
	printf("%d", as + bs - ma - mb);

	return 0;
}
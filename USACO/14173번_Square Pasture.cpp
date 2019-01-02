/*
백준 14173 (https://www.acmicpc.net/problem/14173)
모든 입력된 좌표들을 포함하기 위해 x,y에 대해 가장 작은값, 가장 큰 값을 찾는다.
그 차이가 큰 것을 한 변으로 하는 정사각형의 넓이 출력
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int x1, y1, x2, y2, nx, ny, mx, my, ans;
	int maxX, maxY, minX, minY;
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	scanf("%d %d %d %d", &nx, &ny, &mx, &my);
	maxX = max({ x2,nx,mx });
	maxY = max({ y2,ny,my });
	minX = min({ x1,nx,mx });
	minY = min({ y1,ny,my });
	ans = max((maxX - minX), (maxY - minY));
	printf("%d", ans*ans);

	return 0;
}
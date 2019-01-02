/*
���� 14173 (https://www.acmicpc.net/problem/14173)
��� �Էµ� ��ǥ���� �����ϱ� ���� x,y�� ���� ���� ������, ���� ū ���� ã�´�.
�� ���̰� ū ���� �� ������ �ϴ� ���簢���� ���� ���
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
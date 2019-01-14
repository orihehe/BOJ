/*
BOJ 2022 (https://www.acmicpc.net/problem/2022)
�׸��� �ִ� ? �� �̺�Ž������ ���� ������ ���Ѵ�. - (mid)
? ���� �ְ� �Ǹ� �� �ﰢ���� ���� �� ��(lh)�� ���� �� �ְ�
�־��� c�� ������ lh�� ������ �ﰢ���� �������� c������ �������� �غ��� �������� ���� �׾��� �� 
������ ���� �ﰢ���� �غ��� ���� �ﰢ���� �غ��� ������ ���ٴ� ���� �̿��Ͽ� ���� �ﰢ���� �غ��� ���Ѵ�.
�ٸ� �ﰢ�� ���� ���� ������� �غ��� ���ϰ�, �� ������ ��(tmp)�� ?�� ���� ���Ѵ�.
���� tmp�� ���� mid�� ������ ũ�ٸ� �� ��ٸ��� ������ ���̰� c���� �۴ٴ� ���̹Ƿ� r=mid�� mid���� �ٿ��� �Ѵ�.
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	double x, y, c, lh, rh, l, r, mid;
	scanf("%lf %lf %lf", &x, &y, &c);
	l = 0, r = max(x, y);
	for (int i = 0; i<100; i++) {
		mid = (l + r) / 2;
		lh = sqrt(x * x - mid * mid);
		rh = sqrt(y * y - mid * mid);
		double tmp = mid * c / lh + mid * c / rh;
		if (mid > tmp) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	printf("%.3lf", mid);

	return 0;
}